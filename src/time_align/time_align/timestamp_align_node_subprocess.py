#!/usr/bin/env python3

import os
import numpy as np
import rclpy
from rclpy.node import Node

from sensor_msgs.msg import PointCloud2
from visualization_msgs.msg import MarkerArray
from std_msgs.msg import Header
from datetime import datetime, timezone
from sensor_msgs_py import point_cloud2
# from msg import sync_pc

from message_filters import Subscriber, ApproximateTimeSynchronizer
from pc_msg.msg import SyncPc
from stamp_markerarray.msg import StampedMarkerArray
import concurrent.futures  # 确保已经导入

class PointCloudSynchronizer(Node):
    def __init__(self, save_pcd=False):
        super().__init__('pointcloud_synchronizer')

        self.save = save_pcd

        # 定义要订阅的点云话题列表
        self.topics = [
            # '/szyradarobjectmsg_9A/points_raw',
            '/szyradarobjectmsg_9B/points_raw',
            # '/szyradarobjectmsg_9C/points_raw',
            '/szyradarobjectmsg_9D/points_raw',

            # '/R9_Ae_LidN/FP_lidar/pcl_output_North',
            # '/R9_Aw_LidN/FP_lidar/pcl_output_North',
            # '/R9_Bn_LidE/FP_lidar/pcl_output_East',
            '/R9_Bn_LidW/FP_lidar/pcl_output_West',
            '/R9_Ds_LidE/FP_lidar/pcl_output_East',

            '/stamped/perc_bbox/G32050700009A01',
            '/stamped/perc_bbox/G32050700009B01',
            '/stamped/perc_bbox/G32050700009M00'


        ]

        self.pointcloud_subscribers = []
        self.pointcloud_publishers = []
        self.marker_subscribers = []
        self.marker_publishers = []

        # 动态创建订阅者和发布者
        for topic in self.topics[:-3]:
            sub = Subscriber(self, PointCloud2, topic)
            self.pointcloud_subscribers.append(sub)
            self.get_logger().info(f'Subscribed to {topic}')
            self.get_logger().info('消息类型：{}'.format(sub.msg_type))

            # 创建对应的发布者，修改 topic 名字以区别
            pub_topic = 'SYNC' + topic.upper()  # 或者添加后缀，例如：topic + '_SYNC'
            pub = self.create_publisher(PointCloud2, pub_topic, 10)
            self.pointcloud_publishers.append(pub)
            self.get_logger().info(f'Publisher created for {pub_topic}')
        
        for topic in self.topics[-3:]:
            sub = Subscriber(self, StampedMarkerArray, topic)
            self.marker_subscribers.append(sub)
            self.get_logger().info(f'Subscribed to {topic}')
            self.get_logger().info('消息类型：{}'.format(sub.msg_type))

            # 创建对应的发布者，修改 topic 名字以区别
            pub_topic = 'SYNC' + topic.upper()
            pub = self.create_publisher(MarkerArray, pub_topic, 10)
            self.marker_publishers.append(pub)


        # 创建时间同步器
        self.ts = ApproximateTimeSynchronizer(
            self.pointcloud_subscribers + self.marker_subscribers,
            # self.marker_subscribers,
            queue_size=1000,
            slop=0.1  # 允许的时间偏差（秒）
        )
        self.ts.registerCallback(self.maincallback)

        self.pool_executor = concurrent.futures.ThreadPoolExecutor(max_workers=4)  # 修改属性名

        self.get_logger().info('PointCloudSynchronizer node has been started.')

    def maincallback(self, *msgs):
        if self.save:
            self.get_logger().info('准备保存点云数据...')
            self.save_pcd_callback(*msgs[:-3])

        self.sync_callback(*msgs)

    def save_pcd_callback(self, *pointclouds):
        # 确保接收到的点云数量与订阅的数量一致
        if len(pointclouds) != len(self.topics[:-3]):
            self.get_logger().warn('Received unexpected number of pointclouds.')
            return
        
        msg_timestamps = pointclouds[0].header.stamp.sec * 1e9 + pointclouds[0].header.stamp.nanosec
        utc_time = datetime.fromtimestamp(msg_timestamps / 1e9, timezone.utc).strftime('%Y-%m-%d_%H-%M-%S-%f')[:-3]
        directory = f"/home/tyjt/桌面/毫米波雷达/同步2/{utc_time}"
        os.makedirs(directory, exist_ok=True)
        
        self.get_logger().info('开始处理点云')
        self.get_logger().info(f'Pool Executor: {self.pool_executor}')
        #多线程处理保存点云
        futures = [
            self.pool_executor.submit(self.save_pcd, directory, pc, topic)
            for pc, topic in zip(pointclouds, self.topics[:-3])
        ]
        # for pc, topic in zip(pointclouds, self.topics[:-3]):
        #     self.save_pcd(directory, pc, topic)
        #     self.get_logger().info(f'保存点云数据到{directory}')

    def save_pcd(self, directory, pointcloud, topic):

        self.get_logger().info(f'接收到来自{topic}的点云数据')
        if "szyradarobjectmsg" in topic:
            # 解析点云数据
            self.get_logger().info('开始保存radar点云数据...')
            pc_data = list(point_cloud2.read_points(
                pointcloud, 
                field_names=("x", "y", "z", "vx", "vy", "vz", "intensity", "ring", "roi_flag"),  
                skip_nans=True))
            pc_data_np = np.array(pc_data, dtype=[
                ('x', np.float32), 
                ('y', np.float32), 
                ('z', np.float32), 
                ('vx', np.float32), 
                ('vy', np.float32), 
                ('vz', np.float32), 
                ('intensity', np.uint8), 
                ('ring', np.uint8), 
                ('roi_flag', np.uint32)
            ])

            header = (
                "# .PCD v0.7 - Point Cloud Data file format\n"
                "VERSION 0.7\n"
                "FIELDS x y z vx vy vz intensity ring roi_flag\n"
                "SIZE 4 4 4 4 4 4 1 1 4\n"
                "TYPE F F F F F F U U U\n"
                "COUNT 1 1 1 1 1 1 1 1 1\n"
                f"WIDTH {pc_data_np.shape[0]}\n"
                "HEIGHT 1\n"
                "VIEWPOINT 0 0 0 1 0 0 0\n"
                f"POINTS {pc_data_np.shape[0]}\n"
                "DATA ascii\n"
            )

            _filename = topic.replace('/', '_')  
            filename = f"{directory}/{_filename}.pcd"
        
            with open(filename, 'w') as f:
                f.write(header)
                for point in pc_data_np:
                    f.write(f"{point['x']} {point['y']} {point['z']} {point['vx']} {point['vy']} {point['vz']} "
                        f"{point['intensity']} {point['ring']} {point['roi_flag']}\n")
        else:
        # 解析点云数据
            self.get_logger().info('开始保存lidar点云数据...')
            pc_data = list(point_cloud2.read_points(
                pointcloud, 
                field_names=("x", "y", "z", "intensity", "ring", "timestamp_2us"), 
                skip_nans=True))
            pc_data_np = np.array(pc_data, dtype=[
                ('x', np.float32), 
                ('y', np.float32), 
                ('z', np.float32), 
                ('intensity', np.uint8), 
                ('ring', np.uint8), 
                ('timestamp_2us', np.uint16)
            ]) 

            header = (
                "# .PCD v0.7 - Point Cloud Data file format\n"
                "VERSION 0.7\n"
                "FIELDS x y z intensity ring timestamp_2us\n"
                "SIZE 4 4 4 1 1 2\n"
                "TYPE F F F U U U\n"
                "COUNT 1 1 1 1 1 1\n"
                f"WIDTH {pc_data_np.shape[0]}\n"
                "HEIGHT 1\n"
                "VIEWPOINT 0 0 0 1 0 0 0\n"
                f"POINTS {pc_data_np.shape[0]}\n"
                "DATA ascii\n"
            )

            _filename = topic.replace('/', '_')  
            filename = f"{directory}/{_filename}.pcd" 

            with open(filename, 'w') as f:
                f.write(header)
                for point in pc_data_np:
                    f.write(f"{point['x']} {point['y']} {point['z']} {point['intensity']} {point['ring']} {point['timestamp_2us']}\n")          

        
        return self.get_logger().info(f'Saved point cloud to {filename}')
    
    def sync_callback(self, *pointclouds):
        # 确保接收到的点云数量与订阅的数量一致
        if len(pointclouds) != len(self.topics):
            self.get_logger().warn('Received unexpected number of pointclouds.')
            return
        
        self.get_logger().info('-----Received synchronized pointclouds.-----')
        synchronized_msg = SyncPc()
        synchronized_msg.header = Header()
        synchronized_msg.header.stamp = self.get_clock().now().to_msg()

        synchronized_msg.pointclouds = list(pointclouds)  # 将点云数据放入数组

        # 拿到每个点云的原始时间戳并转换成UTC时间打印
        for pc in synchronized_msg.pointclouds:
            timestamp = pc.header.stamp.sec * 1e9 + pc.header.stamp.nanosec
            utc_time = datetime.fromtimestamp(timestamp / 1e9, timezone.utc).\
                                                strftime('%Y-%m-%d %H:%M:%S.%f')[:-3]
            self.get_logger().info(f'Pointcloud timestamp: {utc_time}')

        #定义变换矩阵
        transform_matrix = {
            "R9_Ae_LidN": [
                [0.922266, 0.385342, 0.030614, -244.872977],
                [-0.386493, 0.917787, 0.091047, 64.664415],
                [0.006987, -0.095802, 0.995376, 18.760398],
                [0.000000, 0.000000, 0.000000, 1.000000]
            ],
            "R9_Aw_LidN": [
                [-0.918079, -0.395869, -0.020468, -248.670659],
                [0.396395, -0.917053, -0.043407, 90.869183],
                [-0.001587, -0.047964, 0.998848, 18.546234],
                [0.000000, 0.000000, 0.000000, 1.000000]
            ],
            "R9_Bn_LidE": [
                [-0.490171, 0.870716, 0.039812, -213.111026],
                [-0.870990, -0.487557, -0.060536, 12.262489],
                [-0.033299, -0.064349, 0.997372, 17.669276],
                [0.000000, 0.000000, 0.000000, 1.000000]
            ],
            "R9_Bn_LidW": [
                [0.466102, -0.879800, -0.093278, -213.785501],
                [0.884467, 0.465943, 0.024819, 11.448948],
                [0.021627, -0.094069, 0.995331, 17.724652],
                [0.000000, 0.000000, 0.000000, 1.000000]
            ],
            "R9_Ds_LidE": [
                [-0.447388, 0.889511, 0.092809, -316.482456],
                [-0.894234, -0.446521, -0.031072, 35.785504],
                [0.013802, -0.096894, 0.995199, 17.985855],
                [0.000000, 0.000000, 0.000000, 1.000000]
            ],
            "szyradarobjectmsg_9B": [
                [-0.905725, -0.423811, -0.006829, -215.572021],
                [0.423864, -0.905646, -0.012043, 13.873295],
                [-0.001080, -0.013802, 0.999904, 12.353616],
                [0.000000, 0.000000, 0.000000, 1.000000]
            ],#1205版本
            "szyradarobjectmsg_9D": [
                [0.900210, 0.435425, 0.005061, -314.928436],
                [-0.435455, 0.900150, 0.010520, 35.928085],
                [0.000025, -0.011674, 0.999932, 11.527899],
                [0.000000, 0.000000, 0.000000, 1.000000]
            ],
            "G32050700009M00": [
                [-0.885733, -0.464193, 0.000000, -265.139136],
                [0.464194, -0.885734, 0.000000, 23.626673],
                [-0.000001, -0.000001, 1.000000, 11.846865],
                [0.000000, 0.000000, 0.000000, 1.000000]
            ]
        }

        # 使用线程池并行处理点云变换
        futures = [
            self.pool_executor.submit(self.pointcloud_transform, pc, transform_matrix, pub.topic_name)
            for pc, pub in zip(pointclouds, self.pointcloud_publishers+self.marker_publishers)
        ]

        for future, pub in zip(futures, self.pointcloud_publishers+self.marker_publishers):
            transformed_pc = future.result()
            self.get_logger().info(f'发步器类型：{type(pub)}')
            # self.get_logger().info(f'消息类型：{transformed_pc}')
            pub.publish(transformed_pc)
            self.get_logger().info(f'Published synchronized pointcloud to {pub.topic_name}')

    def pointcloud_transform(self, msg, transform_matrix, topic_name):
        msg.header.frame_id = 'map'  # 修改 frame_id
        topic_name_lower = topic_name.lower()
        matched = False

        for key in transform_matrix.keys():
            if key.lower() in topic_name_lower:
                matrix = np.array(transform_matrix[key])
                matched = True
                break

        if not matched:
            self.get_logger().warn('话题{}未匹配到变换矩阵'.format(topic_name))
            matrix = np.identity(4) 
            # return msg  # 未匹配到，返回原始消息
        else:
            self.get_logger().info('话题{}成功匹配到变换矩阵'.format(topic_name))
        
        if isinstance(msg, PointCloud2):
            self.get_logger().info(f'匹配到pointcloud话题{topic_name}')
            # 将 PointCloud2 数据转换为 NumPy 数组
            points = np.array(list(point_cloud2.read_points(msg, field_names=("x", "y", "z"), skip_nans=True)))
            # points_ = list(point_cloud2.read_points(msg, field_names=("x", "y", "z"), skip_nans=True))
            # self.get_logger().info(f'Pointcloud类型: {type(points_)}')
            # self.get_logger().info(f'提取Pointcloud: {points_}')
            self.get_logger().info(f'Pointcloud: {len(points.shape)}')
            # 提取 x, y, z 列并转换为 float64 类型
            try:
                points = np.vstack((points['x'], points['y'], points['z'])).T.astype(np.float64)
            except IndexError as e:
                self.get_logger().warn('点云数据已经是一个二维数组')
                points = points[:, :3].astype(np.float64)

            # 将点云数据转换为齐次坐标
            ones = np.ones((points.shape[0], 1))
            points_homogeneous = np.hstack([points, ones])

            # 应用变换矩阵
            transformed_points_homogeneous = points_homogeneous.dot(matrix.T)

            # 转换回普通坐标
            transformed_points = transformed_points_homogeneous[:, :3]

            # 将变换后的 NumPy 数组转换回 PointCloud2
            transformed_msg = point_cloud2.create_cloud_xyz32(msg.header, transformed_points)

            return transformed_msg
        
        elif isinstance(msg, StampedMarkerArray):
            self.get_logger().info(f'匹配到marker话题{topic_name}')

            #把msg中的markers封装进MarkerArray
            transformed_msg = MarkerArray()
            # for marker in msg.markers:
            #     transformed_msg.markers.append(marker)
            transformed_msg.markers = msg.markers
            return transformed_msg
            
        else:
            self.get_logger().warn('未知消息类型')
            # return self.get_logger().info(f'转换后的数据类型{type(msg)}')

 

def main(args=None):
    rclpy.init(args=args)
    node = PointCloudSynchronizer(save_pcd=False)
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
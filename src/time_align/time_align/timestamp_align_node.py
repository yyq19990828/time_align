#!/usr/bin/env python3

import numpy as np
import rclpy
from rclpy.node import Node

from sensor_msgs.msg import PointCloud2
from std_msgs.msg import Header
from datetime import datetime, timezone
from sensor_msgs_py import point_cloud2
# from msg import sync_pc

from message_filters import Subscriber, ApproximateTimeSynchronizer
from pc_msg.msg import SyncPc

class PointCloudSynchronizer(Node):
    def __init__(self):
        super().__init__('pointcloud_synchronizer')

        # 定义要订阅的点云话题列表
        self.topics = [
            '/szyradarobjectmsg_9A/points_raw',
            '/szyradarobjectmsg_9B/points_raw',
            '/szyradarobjectmsg_9C/points_raw',
            '/szyradarobjectmsg_9D/points_raw',

            '/R9_Ae_LidN/FP_lidar/pcl_output_North',
            # '/R9_Aw_LidB/RSBP_lidar/pcl_output_bp',
            '/R9_Aw_LidN/FP_lidar/pcl_output_North',
            # '/R9_Bn_LidB/RSBP_lidar/pcl_output_bp',
            '/R9_Bn_LidE/FP_lidar/pcl_output_East',
            '/R9_Bn_LidW/FP_lidar/pcl_output_West',
            # '/R9_Ce_LidB/RSBP_lidar/pcl_output_bp',
            '/R9_Ds_LidE/FP_lidar/pcl_output_East'

        ]

        self.pointcloud_subscribers = []
        self.pointcloud_publishers = []

        # 动态创建订阅者和发布者
        for topic in self.topics:
            sub = Subscriber(self, PointCloud2, topic)
            self.pointcloud_subscribers.append(sub)
            self.get_logger().info(f'Subscribed to {topic}')

            # 创建对应的发布者，修改 topic 名字以区别
            pub_topic = 'SYNC_' + topic.upper()  # 或者添加后缀，例如：topic + '_SYNC'
            pub = self.create_publisher(PointCloud2, pub_topic, 10)
            self.pointcloud_publishers.append(pub)
            self.get_logger().info(f'Publisher created for {pub_topic}')

        # 创建时间同步器
        self.ts = ApproximateTimeSynchronizer(
            self.pointcloud_subscribers,
            queue_size=1000,
            slop=0.1  # 允许的时间偏差（秒）
        )
        self.ts.registerCallback(self.sync_callback)

        self.get_logger().info('PointCloudSynchronizer node has been started.')

    def sync_callback(self, *pointclouds):
        # 确保接收到的点云数量与订阅的数量一致
        if len(pointclouds) != len(self.topics):
            self.get_logger().warn('Received unexpected number of pointclouds.')
            return
        
        self.get_logger().info('Received synchronized pointclouds.')
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
        # transform_matrix = np.array([[1, 0, 0, 0],
        #                              [0, 1, 0, 0],
        #                              [0, 0, 1, 0],
        #                              [0, 0, 0, 1]])
        # self.get_logger().info(f'Transform matrix: {transform_matrix.shape}')
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
            ],
            "szyradarobjectmsg_9D": [
                [0.900210, 0.435425, 0.005061, -314.928436],
                [-0.435455, 0.900150, 0.010520, 35.928085],
                [0.000025, -0.011674, 0.999932, 11.527899],
                [0.000000, 0.000000, 0.000000, 1.000000]
            ],
        }

        # 逐个发布同步后的点云消息到对应的 topic
        for pc, pub in zip(pointclouds, self.pointcloud_publishers):
            pc.header.frame_id = 'pc_frame'
            pub_topic_name = pub.topic_name  # 获取发布者的主题名字
            pc = self.pointcloud_transform(pc, transform_matrix, pub_topic_name)
            pub.publish(pc)
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
            return msg  # 未匹配到，返回原始消息
        
        self.get_logger().info('话题{}成功匹配到变换矩阵'.format(topic_name))
        
        # 将 PointCloud2 数据转换为 NumPy 数组
        points = np.array(list(point_cloud2.read_points(msg, field_names=("x", "y", "z"), skip_nans=True)))

        # 检查 points 的结构并相应地处理
        if points.dtype.names is not None and all(name in points.dtype.names for name in ('x', 'y', 'z')):
            # 如果 points 是一个结构化数组
            points_xyz = np.vstack((points['x'], points['y'], points['z'])).T
        else:
            # 如果 points 已经是一个普通的 NumPy 数组
            points_xyz = points

        points_xyz = points_xyz.astype(np.float64)
        self.get_logger().info(f'Pointcloud shape: {points_xyz.shape}')

        # 将点云数据转换为齐次坐标
        ones = np.ones((points_xyz.shape[0], 1))
        points_homogeneous = np.hstack([points_xyz, ones])

        # 应用变换矩阵
        transformed_points_homogeneous = points_homogeneous.dot(matrix.T)

        # 转换回普通坐标
        transformed_points = transformed_points_homogeneous[:, :3]

        # 将变换后的 NumPy 数组转换回 PointCloud2
        transformed_msg = point_cloud2.create_cloud_xyz32(msg.header, transformed_points)
        
        return transformed_msg

 

def main(args=None):
    rclpy.init(args=args)
    node = PointCloudSynchronizer()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
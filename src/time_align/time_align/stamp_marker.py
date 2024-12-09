import functools
import rclpy
from rclpy.node import Node
from visualization_msgs.msg import MarkerArray
from stamp_markerarray.msg import StampedMarkerArray  # 替换为您的包名
from rclpy.qos import QoSProfile
from std_msgs.msg import Header

class MarkerArrayWrapper(Node):
    def __init__(self):
        super().__init__('marker_array_wrapper')
        qos = QoSProfile(depth=10)

        self.marker_subs = []
        self.stamped_marker_pubs = []
        self.topics = [
            '/perc_bbox/G32050700009A01',
            '/perc_bbox/G32050700009B01',
            '/perc_bbox/G32050700009M00'
        ]

        for topic in self.topics:
            self.get_logger().info(f'订阅话题 {topic}')
            self.marker_sub = self.create_subscription(
                MarkerArray,
                topic,
                functools.partial(self.marker_callback, topic),
                qos
            )
            self.marker_subs.append(self.marker_sub)
            self.stamped_marker_pub = self.create_publisher(
                StampedMarkerArray,
                f'stamped{topic}',
                qos
            )
            self.stamped_marker_pubs.append(self.stamped_marker_pub)


    def marker_callback(self, topic, msg: MarkerArray):
        if not msg.markers:
            self.get_logger().warn('收到空的 MarkerArray 消息')
            return
        self.get_logger().info(f'收到 MarkerArray，共有 {len(msg.markers)} 个 Marker')
        # 提取最新的时间戳作为整个 MarkerArray 的时间
        max_stamp = msg.markers[0].header.stamp

        stamped_msg = StampedMarkerArray()
        stamped_msg.header = Header()
        stamped_msg.header.stamp = max_stamp
        stamped_msg.markers = msg.markers

        stamped_marker_pub = next(pub for pub in self.stamped_marker_pubs if pub.topic == f'stamped{topic}')
        stamped_marker_pub.publish(stamped_msg)
        self.get_logger().debug(f'发布 StampedMarkerArray，时间: {max_stamp.sec}.{max_stamp.nanosec}')


def main(args=None):
    rclpy.init(args=args)
    wrapper = MarkerArrayWrapper()
    rclpy.spin(wrapper)
    wrapper.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
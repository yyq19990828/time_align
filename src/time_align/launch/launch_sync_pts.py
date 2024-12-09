from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='time_align',
            executable='timestamp_align_pts',
            name='timestamp_align_pts_node',
            output='screen'
        )
    ])
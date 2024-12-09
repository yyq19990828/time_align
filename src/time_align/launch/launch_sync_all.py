from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='time_align',
            executable='stamp_marker_parse',
            name='stamp_marker_parse_node',
            output='screen'
        ),
        Node(
            package='time_align',
            executable='timestamp_align_all',
            name='timestamp_align_all_node',
            output='screen'
        )
    ])
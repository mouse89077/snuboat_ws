from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration



def generate_launch_description():
    return LaunchDescription([
        Node(
            package='snuboat_gps_rtk', 
            executable='snuboat_gps_rtk',
            output='screen',
        )
    ])
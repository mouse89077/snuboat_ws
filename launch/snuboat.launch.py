import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource


def generate_launch_description():
   snuboat_gps_rtk = IncludeLaunchDescription(
      PythonLaunchDescriptionSource([os.path.join(
         get_package_share_directory('snuboat_gps_rtk'), 'launch'),
         '/snuboat_gps_rtk.launch.py'])
      )
   rplidar_a3 = IncludeLaunchDescription(
      PythonLaunchDescriptionSource([os.path.join(
         get_package_share_directory('rplidar_ros'), 'launch'),
         '/rplidar_a3_launch.py'])
      )
   imu = IncludeLaunchDescription(
      PythonLaunchDescriptionSource([os.path.join(
         get_package_share_directory('microstrain_inertial_driver'), 'launch'),
         '/microstrain_launch.py'])
      )
   snuboat_nav = IncludeLaunchDescription(
      PythonLaunchDescriptionSource([os.path.join(
         get_package_share_directory('snuboat_nav'), 'launch'),
         '/snuboat_nav.launch.py']),
      )

   return LaunchDescription([
      snuboat_gps_rtk,
      rplidar_a3,
      imu,
      snuboat_nav,
   ])
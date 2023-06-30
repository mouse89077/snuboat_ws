# KABOAT
import rclpy
import os
import yaml
from rclpy.node import Node
from geometry_msgs.msg import Point
from std_msgs.msg import String
import pymap3d as pm
import numpy as np

class GNSSConverter(Node):
    def __init__(self):
        super().__init__('gnss_converter')

        # config_file = os.path.join(os.path.dirname(__file__), '..', 'config', 'gnss_config.yaml')
        # with open(config_file, 'r') as file:
        #     config = yaml.safe_load(file)
        #     self.origin = self.get_parameter('origin').value
        default_params = {
            # to be modified
            'Left_Bottom' : [37.4557583, 126.9517448], # to be modified
            'Right_Bottom' : [37.4558121667, 126.9517401667],
            'Left_Top' : [37.4556311667, 126.9518098333], # to be modified
            'Right_Top' : [37.4556311667, 126.9518098333], # to be modified
            'origin' : [37.4557583, 126.9517448], # to be modified, same as Left_Bottom
        }
        self.Left_Bottom = self.declare_parameter("Left_Bottom", default_params['Left_Bottom']).value
        self.Right_Bottom = self.declare_parameter("Right_Bottom", default_params['Right_Bottom']).value
        self.Left_Top = self.declare_parameter("Left_Top", default_params['Left_Top']).value
        self.Left_Top = self.declare_parameter("Right_Top", default_params['Right_Top']).value

        self.origin = self.declare_parameter("origin", default_params['origin']).value

        self.pos = [0, 0, 0]

        self.gps_lon_sub = self.create_subscription(String, '/gps/lon', self.gps_lon_callback, 1)
        self.gps_lat_sub = self.create_subscription(String, '/gps/lat', self.gps_lat_callback, 1)
        
        self.enu_pos_pub = self.create_publisher(Point, '/enu_pos', 1)
        self.OS_timer = self.create_timer(0.1, self.pub_enu_pos)

        self.enu_pos_log_pub = self.create_publisher(String, '/log/enu_pos', 1)

        self.gps_lon_received = False
        self.gps_lat_received = False

    def wait_for_topics(self):
        self.timer = self.create_timer(1.0, self.check_topics_status)

    def check_topics_status(self):
        if not self.gps_lat_received:
            self.get_logger().info('No topic gps_lat_received')
        if not self.gps_lon_received:
            self.get_logger().info('No topic gps_lon_received')
        if self.gps_lat_received and self.gps_lon_received:
            self.get_logger().info('All topics received')
        else:
            self.get_logger().info('Waiting for topics to be published...')

    def gps_lon_callback(self, msg):
        self.gps_lon_received = True
        str_gps_lon = msg.data
        self.gps_lon = float(str_gps_lon)

    def gps_lat_callback(self, msg):
        self.gps_lat_received = True
        str_gps_lat = msg.data
        self.gps_lat = float(str_gps_lat)

    def enu_convert(self, gnss):
        e, n, u = pm.geodetic2enu(gnss[0], gnss[1], 0, self.origin[0], self.origin[1], 0)
        return e, n, u
    
    def pub_enu_pos(self):
        if self.gps_lat_received and self.gps_lon_received:
            self.pos[0], self.pos[1], self.pos[2] = self.enu_convert([self.gps_lat, self.gps_lon])
            enu_pos = Point()
            enu_pos.x = self.pos[0]
            enu_pos.y = self.pos[1]
            self.enu_pos_pub.publish(enu_pos)
            
            enu_pos_log = String()
            enu_pos_log.data = str(self.pos[0]) + "," + str(self.pos[1])
            self.enu_pos_log_pub.publish(enu_pos_log)

def main(args=None):
    rclpy.init(args=args)
    gnss_converter = GNSSConverter()
    gnss_converter.wait_for_topics()
    rclpy.spin(gnss_converter)
    gnss_converter.destroy_node()
    rclpy.shutodown()

if __name__ == '__main__':
    main()
 

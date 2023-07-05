import rclpy
import os
import yaml
from rclpy.node import Node
from geometry_msgs.msg import Point
from std_msgs.msg import Float64
import numpy as np

class Dummy_ENU_Publisher(Node):
    def __init__(self):
        super().__init__('dummy_enu_publisher')


        self.dt = 0.1
        self.OS_enu_x = np.linspace(0, 100, 100)
        self.OS_enu_y = np.linspace(0, 0, 100)

        self.cnt = 0

        self.OS_enu_pos_pub = self.create_publisher(Point, '/enu_pos', 1)
        self.OS_heading_pub = self.create_publisher(Float64, '/heading', 1)

        self.timer = self.create_timer(self.dt, self.pub_enu_pos)


    def pub_enu_pos(self):
        OS_enu_pos_p = Point()
        OS_enu_pos_p.x = self.OS_enu_x[self.cnt]
        OS_enu_pos_p.y = self.OS_enu_y[self.cnt]
        self.OS_enu_pos_pub.publish(OS_enu_pos_p)

        OS_heading_pub_ = Float64()
        if self.cnt != 0:
            OS_heading_pub_.data = np.arctan2(self.OS_enu_y[self.cnt] - self.OS_enu_y[self.cnt - 1], self.OS_enu_x[self.cnt] - self.OS_enu_x[self.cnt - 1])
        else:
            OS_heading_pub_.data = 0
        self.OS_heading_pub.publish(OS_heading_pub_)      

        self.cnt += 1
        if self.cnt == len(self.OS_enu_x):
            self.get_logger().info('Exiting dummy_enu_publisher')
        else:
            self.get_logger().info('Executing dummy_enu_publisher')
        

def main(args=None):
    rclpy.init(args=args)
    dummy_enu_pub = Dummy_ENU_Publisher()
    rclpy.spin(dummy_enu_pub)
    dummy_enu_pub.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

        

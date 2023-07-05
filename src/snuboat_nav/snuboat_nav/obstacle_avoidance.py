# KABOAT
import rclpy
import os
import yaml
from rclpy.node import Node
from geometry_msgs.msg import Point
from std_msgs.msg import Bool, Float64, Float64MultiArray
from sensor_msgs import LaserScan
import numpy as np

class Obstacle_Avoidance(Node):
    def __init__(self):
        super().__init__('lidar_converter')
        
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
        self.dt = 0.1
        self.waypoint = []
        
        self.enu_pos_sub = self.create_subscription(Float64, '/enu_pos', self.enu_pos_callback, 1)
        self.heading_sub = self.create_subscription(Float64, '/heading', self.heading_callback, 1)
        self.spd_sub = self.create_subscription(Float64, '/spd', self.spd_callback, 1)
        self.obstacles_sub = self.create_subscription(Float64MultiArray, '/obstacles', self.obstacles_callback, 1)
        self.wp_sub = self.create_subscription(Float64, '/enu_wp',self.enu_wp_callback,1)

        self.des_heading_pub = self.create_publisher(Float64, '/des_heading', 1)
        self.des_spd_pub = self.create_publisher(Float64, '/des_spd', 1)
        
        self.des_pub = self.create_timer(self.dt, self.pub_des)
        
        self.enu_pos_received = False
        self.heading_received = False
        self.spd_received = False
        self.obstacles_received = False
        self.enu_wp_received = False
        
        # why 10?
        self.enu_pos = np.zeros((10, 2))
        self.enu_wp_pos = np.zeros((10,2))
        self.heading = np.zeros(10)
        self.spd = np.zeros(10)
        self.obstacles = []
        self.obstacles_points = []
        
        #
        self.ref_heading = 0
        self.safe_radius = 1.5
        self.safe_obs = []
        self.des_heading = np.zeros(10) # why 10?
        self.des_spd = np.zeros(10)
                
    def wait_for_topics(self):
        self.check_topic_status
        
    def check_topic_status(self):
        if not self.enu_pos_received:
            self.get_logger().info('No topic enu_pos_received')
        if not self.heading_received:
            self.get_logger().info('No topic heading_received')
        if not self.spd_received:
            self.get_logger().info('No topic spd_received')
        if not self.obstacles_received:
            self.get_logger().info('No topic obstacles_received')
        if self.enu_pos_received and self.heading_received and self.spd_received and self.obstacles_received:
            self.get_logger().info('All topics received')
        else: 
            self.get_logger().info('Waiting for topics to be published')
            
    def enu_pos_callback(self, msg):
        self.enu_pos_received = True
        self.enu_pos = np.append(self.enu_pos, [[msg.x, msg.y]], axis=0)
        self.enu_pos = self.enu_pos[1:]

    def enu_wp_callback(self,msg):
        self.enu_wp_received = True
        self.enu_wp_pos = np.append(self.enu_wp_pos, [[msg.x, msg.y]], axis=0)
        self.enu_wp_pos = self.enu_wp_pos[1:]
 

    def heading_callback(self, msg):
        self.heading_received = True
        self.heading = np.append(self.heading, msg.data)
        self.heading = self.heading[1:]
    
    def spd_callback(self, msg):
        self.spd_received = True
        self.spd = np.append(self.spd, msg.data)
        self.spd = self.spd[1:]
        
    def obstacles_callback(self, msg):
        self.obstacles_received = True
        self.obstacles = msg.data
        
    def pub_des(self):        
        des_heading = Float64()
        des_heading.data = self.des_heading[-1]
        self.des_heading_pub.publish(des_heading)
        
        des_spd = Float64()
        des_spd.data = self.des_spd[-1]
        self.des_spd_pub.publish(des_spd) 
        
    def cal_des(self):
        pos_heading = np.linspace(-179, 179, 1)
        cur_pos = self.enu_pos[-1, :]
        # wp ref heading
        self.ref_heading =np.rad2deg(np.arctan2(self.enu_wp_pos[1] - cur_pos[1], self.enu_wp_pos[0] - cur_pos[0]))

        if len(self.obstacles) == 0:
            obstacle_num = 0
        else:
            obstacle_num = len(self.obstacles[:, 0])
        #### calculate des_heading and des_spd
        if obstacle_num != 0:
            # self.obstacles => [[label r phi x y]]
            for i in range(obstacle_num):
                # r
                distance = self.obstacles[i,2]
                if distance<self.safe_radius:
                    # danger obs
                    continue
                else:
                    # safe obs => save phi 
                    self.safe_obs = np.append(self.safe_obs,self.obstacles[i,3],axis=0)
                    
                # min_grad = np.arctan2(self.obstacles[i, 1] - cur_pos[1], self.obstacles[i, 0] - cur_pos[0])
                # max_grad = np.arctan2(self.obstacles[i, -1] - cur_pos[1], self.obstacles[i, -2] - cur_pos[0])
                # min_grad = np.rad2deg(min_grad)
                # max_grad = np.rad2deg(max_grad)
            #     min_grad = self.obstacles[i,3]
            #     max_grad = self.obstacles[i,3]


            #     # idx = np.where(cur_pos < min_grad and cur_pos > max_grad)


            self.des_heading = 0
        else:
            # previous des_heading value
            des_heading = self.des_heading[-1]
            des_spd = self.des_spd[-1]
        
        self.des_heading = np.append(self.des_heading, des_heading)
        self.des_heading = self.des_heading[-1]
        self.des_spd = np.append(self.des_spd, des_spd)
        self.des_spd = self.des_spd[-1]
        
def main(args=None):
    rclpy.init(args=args)
    obstacle_avoidance = Obstacle_Avoidance()
    rclpy.spin(obstacle_avoidance)
    obstacle_avoidance.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()        
    

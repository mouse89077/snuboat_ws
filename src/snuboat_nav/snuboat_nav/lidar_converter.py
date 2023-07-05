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
            # to be filled 
        }
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

        ##??
        # why 10?
        self.enu_pos = np.zeros((10, 2))
        self.enu_wp_pos = np.zeros((10,2))
        self.heading = np.zeros(10)
        self.spd = np.zeros(10)
        self.obstacles = []
        self.obstacles_points = []

        ######

        #
        self.ref_heading = 0
        self.safe_radius = 1.5
        self.safe_obs = []
        self.des_heading = np.zeros(10) # why 10?
@@ -71,11 +71,13 @@ def enu_pos_callback(self, msg):
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
@@ -102,6 +104,9 @@ def pub_des(self):
    def cal_des(self):
        pos_heading = np.linspace(-179, 179, 1)
        cur_pos = self.enu_pos[-1, :]
        # wp ref heading
        self.ref_heading =np.rad2deg(np.arctan2(self.enu_wp_pos[1] - cur_pos[1], self.enu_wp_pos[0] - cur_pos[0]))

        if len(self.obstacles) == 0:
            obstacle_num = 0
        else:
@@ -116,13 +121,9 @@ def cal_des(self):
                    # danger obs
                    continue
                else:
                    # safe obs
                    self.safe_obs = np.append(self.safe_obs,self.obstacles[i],axis=0)





                    # safe obs => save phi 
                    self.safe_obs = np.append(self.safe_obs,self.obstacles[i,3],axis=0)

                # min_grad = np.arctan2(self.obstacles[i, 1] - cur_pos[1], self.obstacles[i, 0] - cur_pos[0])
                # max_grad = np.arctan2(self.obstacles[i, -1] - cur_pos[1], self.obstacles[i, -2] - cur_pos[0])
                # min_grad = np.rad2deg(min_grad)
@@ -132,11 +133,7 @@ def cal_des(self):


            #     # idx = np.where(cur_pos < min_grad and cur_pos > max_grad)


            #   danger obs

            #   safe obs

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

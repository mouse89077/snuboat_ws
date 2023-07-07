# KABOAT
import rclpy
import os
import yaml
from rclpy.node import Node
from geometry_msgs.msg import Point
from rclpy.qos import qos_profile_sensor_data
from std_msgs.msg import Bool, Float64, Float64MultiArray
from sensor_msgs import LaserScan
import numpy as np
from sklearn.cluster import DBSCAN
from sklearn.preprocessing import StandardScaler

class Lidar_Converter(Node):
    def __init__(self):
        super().__init__('lidar_converter')
        
        self.dt = 0.1
        self.polar_scan = []
        self.cart_scan = [] # origin: boat
        
        self.lidar_scan_sub = self.create_subscription(LaserScan, '/scan', self.lidar_scan_callback, qos_profile_sensor_data)
        
        self.obs_labels_pub = self.create_publisher(Float64MultiArray, '/obs/labels', 1)
        self.obs_r_pub = self.create_publisher(Float64MultiArray, '/obs/r', 1)
        self.obs_phi_pub = self.create_publisher(Float64MultiArray, '/obs/phi', 1)
        self.obs_x_pub = self.create_publisher(Float64MultiArray, '/obs/x', 1)
        self.obs_y_pub = self.create_publisher(Float64MultiArray, '/obs/y', 1)
        
        self.obstacles_timer = self.create_timer(self.dt, self.pub_obstacles)

        self.lidar_scan_received = False
        
    def wait_for_topics(self):
        self.check_topic_status
        
    def check_topic_status(self):
        if not self.lidar_scan_received:
            self.get_logger().info('Topic lidar_scan not received')
        if not self.lidar_scan_received:
            self.get_logger().info('Waiting for topics to be published')
        else:
            self.get_logger().info('All topics received')
    
    # scan msg => save in polar_pub
    def lidar_scan_callback(self, msg):
        self.lidar_scan_received = True
        #temporary polar coord []
        phi = msg.angle_min # radians
        for r in msg.ranges:
            if msg.range_min <= r <= msg.range_max:
                if len(self.polar_scan)==0:
                    self.polar_scan = [r, phi]
                    self.cart_scan = [r*np.cos(np.radians(phi)), r*np.sin(np.radians(phi))]
                else:
                    self.polar_scan = np.append(self.polar_scan, [[r,phi]],axis=0)
                    self.cart_scan = np.append(self.cart_scan, [[r*np.cos(np.radians(phi)), r*np.sin(np.radians(phi))]], axis = 0)
            phi += msg.angle_increment
            
        points = np.array(self.cart_scan)
        scaler = StandardScaler()
        points_scaled = scaler.fit_transform(points)
        dbscan = DBSCAN(eps=0.5, min_samples=5)  # Adjust the parameters as per your data
        dbscan.fit(points_scaled)
        self.scan_labels = dbscan.labels_
        
    # publish obstacle sinfo
    def pub_obstacles(self):
        obs_labels = Float64MultiArray()
        obs_labels.data = self.scan_labels.tolist()
        obs_r = Float64MultiArray()
        obs_r.data = np.transpose(self.polar_scan[:, 0]).tolist()
        obs_phi = Float64MultiArray()
        obs_phi.data = np.transpose(self.polar_scan[:, 1]).tolist()
        obs_x = Float64MultiArray()
        obs_x.data = np.transpose(self.cart_scan[:, 0]).tolist()
        obs_y = Float64MultiArray()
        obs_y.data = np.transpose(self.cart_scan[:, 1]).tolist()
        
        self.obs_labels_pub.publish(obs_labels)
        self.obs_r_pub.publish(obs_r)
        self.obs_phi_pub.publish(obs_phi)
        self.obs_x_pub.publish(obs_x)
        self.obs_y_pub.publish(obs_y)
        
        
def main(args=None):
    rclpy.init(args=args)
    lidar_converter = Lidar_Converter()
    rclpy.spin(lidar_converter)
    lidar_converter.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

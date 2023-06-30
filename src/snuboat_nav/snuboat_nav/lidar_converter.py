# KABOAT
import rclpy
import os
import yaml
from rclpy.node import Node
from geometry_msgs.msg import Point
from std_msgs.msg import Bool, Float64, Float64MultiArray
from sensor_msgs import LaserScan
import numpy as np
from sklearn.cluster import DBSCAN
from sklearn.preprocessing import StandardScaler

class Lidar_Converter(Node):
    def __init__(self):
        super().__init__('lidar_converter')
        
        default_params = {
            
        }
        self.dt = 0.1
        self.obstacle = []
        self.obstacles = []
        self.cartesian_scan = [] # origin: boat
        
        self.lidar_scan_sub = self.create_publisher(LaserScan, '/lidar_scan', self.lidar_scan_callback, 1)
        
        self.obstacles_pub = self.create_subscription(Float64MultiArray, '/obstacles', 1)
        
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
    
    def lidar_scan_callback(self, msg):
        self.lidar_scan_received = True
        
        phi = msg.angle_min # radians
        for r in msg.ranges:
            if msg.range_min <= r <= msg.range_max:
                p = Point.polar_to_cartesian(r, phi)
                self.cartesian_scan = np.append(self.cartesian_scan, p, axis = 0)
            phi += msg.angle_increment
            
        points = np.array(self.cartesian_scan)
        scaler = StandardScaler()
        points_scaled = scaler.fit_transform(points)
        dbscan = DBSCAN(eps=0.5, min_samples=5)  # Adjust the parameters as per your data
        dbscan.fit(points_scaled)
        self.scan_labels = dbscan.labels_
        
    def pub_obstacles(self):
        if max(self.scan_labels) != -1:
            for i in range(max(self.scan_labels)):
                idxs = np.where(self.scan_labels == i)[0]
                self.obstacle = self.cartesian_scan[idxs, :]
                self.obstacle = np.reshape(self.obstacle, (1, -1))
                self.obstacles[i] = self.obstacle
        # else: self.obstacles = []
            
        obs = Float64MultiArray()
        obs.data = self.obstacles
        self.obstacles_pub.publish(obs)
        
def main(args=None):
    rclpy.init(args=args)
    lidar_converter = Lidar_Converter()
    rclpy.spin(lidar_converter)
    lidar_converter.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
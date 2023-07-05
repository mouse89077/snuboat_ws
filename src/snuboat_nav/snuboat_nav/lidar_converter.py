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
        self.cart_scan = [] # origin: boat
        self.polar_scan = [] # origin: boat

        # subscriber
        self.lidar_scan_sub = self.create_subscription(LaserScan, '/lidar_scan', self.lidar_scan_callback, 1)

        # publisher
        self.obstacles_pub = self.create_publisher(Float64MultiArray, '/obstacles', 1)
        self.polar_scan_pub = self.create_publisher(Float64MultiArray, '/polar_scan', 1)
        self.cart_scan_pub = self.create_publisher(Float64MultiArray, '/cart_scan', 1)
        self.cluster_label_pub = self.create_publisher(Float64MultiArray, '/cluster_label', 1)
        
        self.obstacles_timer = self.create_timer(self.dt, self.pub_obstacles)
        
        #publish => (labels, r, phi)
        # [[labels, r1,phi1]
        #  [label2, r2,phi2]]
        # self.polar_scan =np.empty((0,3),int)

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
        #temporary polar coord []
        temp_polar = []
        phi = msg.angle_min # radians
        for r in msg.ranges:
            if msg.range_min <= r <= msg.range_max:
                self.polar_scan = np.append(self.polar_scan, [[r,phi]],axis=0)
                p = Point.polar_to_cartesian(r, phi)
                self.cart_scan = np.append(self.cart_scan, p, axis = 0)
            phi += msg.angle_increment
            
        points = np.array(self.cart_scan)
        scaler = StandardScaler()
        points_scaled = scaler.fit_transform(points)
        dbscan = DBSCAN(eps=0.5, min_samples=5)  # Adjust the parameters as per your data
        dbscan.fit(points_scaled)
        self.scan_labels = dbscan.labels_
        
        # append label to polar coord
        # for i,coord in enumerate(temp_polar):
        #     coord = np.insert(coord,0,self.scan_labels[i])
        #     self.polar_scan = np.append(self.polar_scan,[coord],axis=0)
        
    def pub_obstacles(self):
        self.obstacles = np.zeros((5,max(self.scan_labels)))
        if max(self.scan_labels) != -1:
            for i in range(max(self.scan_labels)):
                idxs = np.where(self.scan_labels == i)[0]
                self.obstacle = self.cartesian_scan[idxs, :]
                self.obstacle = np.reshape(self.obstacle, (1, -1))
                # [[label r phi x y]]
                self.obstacle = np.insert(self.obstacle,0,self.polar_pub[i])
                self.obstacles[i] = self.obstacle # => maybe error? 
        
        # else: self.obstacles = []

        # publish
        obs = Float64MultiArray()
        obs.data = self.obstacles
        self.obstacles_pub.publish(obs)
        lab = Float64MultiArray()
        lab.data = np.reshape(self.scan_labels, (-1, 1))
        self.cluster_label_pub.publish(lab)
        polar_sc = Float64MultiArray()
        polar_sc.data = self.polar_scan
        self.polar_scan_pub.publish(polar_sc)
        cart_sc = Float64MultiArray()
        cart_sc.data = self.cart_scan
        self.cartesian_scan_pub.publish(cart_sc)
        
        
def main(args=None):
    rclpy.init(args=args)
    lidar_converter = Lidar_Converter()
    rclpy.spin(lidar_converter)
    lidar_converter.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

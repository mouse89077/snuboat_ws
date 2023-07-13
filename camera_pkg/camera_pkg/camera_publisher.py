import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import time

class CameraPublisher(Node):
    def __init__(self):
        super().__init__('camera_publisher')
        self.publisher_ = self.create_publisher(Image, '/camera', 10)
        self.timer_ = self.create_timer(0.1, self.timer_callback)  # Adjust the publishing rate as needed
        self.bridge = CvBridge()
        self.capture = cv2.VideoCapture(0)  # Adjust the camera index if needed

    def timer_callback(self):
        ret, frame = self.capture.read()

        if ret:
            image_msg = self.bridge.cv2_to_imgmsg(frame, encoding="bgr8")
            self.publisher_.publish(image_msg)

def main(args=None):
    rclpy.init(args=args)
    camera_publisher = CameraPublisher()
    rclpy.spin(camera_publisher)
    camera_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

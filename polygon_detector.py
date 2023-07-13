import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np
from std_msgs.msg import String, ColorRGBA

class CameraSubscriber(Node):
    def __init__(self):
        super().__init__('camera_subscriber')
        self.subscription = self.create_subscription(
            Image,
            '/camera',  # Replace with the correct camera topic name
            self.listener_callback,
            10
        )
        self.shape_publisher_ = self.create_publisher(String, '/polygon/shape', 10)
        self.color_publisher_ = self.create_publisher(ColorRGBA, '/polygon/color', 10)
        self.bridge = CvBridge()

    def listener_callback(self, msg):
        cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")

        # Perform image processing operations to detect the shape and color
        gray = cv2.cvtColor(cv_image, cv2.COLOR_BGR2GRAY)
        _, threshold = cv2.threshold(gray, 127, 255, cv2.THRESH_BINARY)
        contours, _ = cv2.findContours(threshold, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

        for contour in contours:
            perimeter = cv2.arcLength(contour, True)
            approx = cv2.approxPolyDP(contour, 0.04 * perimeter, True)
            num_vertices = len(approx)

            shape = ""
            color = ColorRGBA()

            if num_vertices == 3:
                shape = "Triangle"
                color.r, color.g, color.b, color.a = 1.0, 0.0, 0.0, 1.0  # Red color
            elif num_vertices == 4:
                x, y, w, h = cv2.boundingRect(approx)
                aspect_ratio = float(w) / h
                if aspect_ratio >= 0.95 and aspect_ratio <= 1.05:
                    shape = "Square"
                    color.r, color.g, color.b, color.a = 0.0, 1.0, 0.0, 1.0  # Green color
                else:
                    shape = "Rectangle"
                    color.r, color.g, color.b, color.a = 0.0, 0.0, 1.0, 1.0  # Blue color
            elif num_vertices == 5:
                shape = "Pentagon"
                color.r, color.g, color.b, color.a = 1.0, 1.0, 0.0, 1.0  # Yellow color
            elif num_vertices == 6:
                shape = "Hexagon"
                color.r, color.g, color.b, color.a = 1.0, 0.0, 1.0, 1.0  # Purple color
            elif num_vertices == 8:
                rect = cv2.minAreaRect(approx)
                box = cv2.boxPoints(rect)
                box = np.int0(box)
                cx = rect[0][0]
                cy = rect[0][1]
                distance = abs(box[0][1] - box[1][1])
                if distance >= 0.95 * abs(box[2][1] - box[3][1]) and distance <= 1.05 * abs(box[2][1] - box[3][1]):
                    shape = "Cross"
                    color.r, color.g, color.b, color.a = 1.0, 0.5, 0.0, 1.0  # Orange color
            else:
                shape = "Circle"
                color.r, color.g, color.b, color.a = 0.0, 1.0, 1.0, 1.0  # Cyan color

            shape_msg = String()
            shape_msg.data = shape
            self.shape_publisher_.publish(shape_msg)

            self.color_publisher_.publish(color)

        cv2.imshow("Camera Image", cv_image)
        cv2.waitKey(1)

def main(args=None):
    rclpy.init(args=args)
    camera_subscriber = CameraSubscriber()
    rclpy.spin(camera_subscriber)
    camera_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

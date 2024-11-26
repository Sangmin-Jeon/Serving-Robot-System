import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class TestNode(Node):
    def __init__(self):
        super().__init__('test_node')
        # Publisher: publishes a string message every second
        self.publisher_ = self.create_publisher(String, 'test_topic', 10)
        self.timer_ = self.create_timer(1.0, self.publish_message)

        # Subscriber: subscribes to the same topic and logs the received messages
        self.subscription_ = self.create_subscription(
            String,
            'test_topic',
            self.topic_callback,
            10)

    def publish_message(self):
        message = String()
        message.data = 'Hello from ROS 2 test node!'
        self.get_logger().info(f'Publishing: "{message.data}"')
        self.publisher_.publish(message)

    def topic_callback(self, msg):
        self.get_logger().info(f'Received: "{msg.data}"')

def main(args=None):
    rclpy.init(args=args)
    node = TestNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
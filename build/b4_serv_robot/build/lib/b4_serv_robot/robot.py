import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from std_msgs.msg import String, Bool
from nav2_msgs.action import NavigateToPose
from rclpy.action import ActionClient
import threading
import time


# rclpy의 Node 클래스를 상속받는 Robot 클래스 정의
class Robot(Node):
    def __init__(self):
        # 초기 위치를 변수로 저장
        self.initial_position = self.create_pose_with_orientation(0.03479859458262814, 0.0015955912501722756, 0.0, 0.0,
                                                                  0.0, -0.002487797055039091, 0.9999969054281183)
        # 'robot'이라는 이름으로 노드 초기화
        super().__init__('robot')

        # 테이블 번호 메시지를 수신하기 위한 구독 생성
        self.subscription = self.create_subscription(
            String,
            'table_no_msg',  # 구독할 토픽 이름
            self.table_callback,  # 수신한 메시지를 처리할 콜백 함수
            10  # 큐 크기
        )

        # 목표 지점 도달 여부를 발행하기 위한 퍼블리셔 생성
        self.publisher_ = self.create_publisher(Bool, 'finished_goal', 10)

        # 로봇에게 네비게이션 목표를 전송하기 위한 액션 클라이언트 생성
        self.action_client = ActionClient(self, NavigateToPose, 'navigate_to_pose')

        # 각 테이블(B1, B2, B3, B4)에 대한 목표 위치 정의
        self.goal_poses = {
            'B1': self.create_pose_with_orientation(3.098488575265936, 1.0186655892629182, 0.0, 0.0, 0.0,
                                                    0.6886346514493831, 0.7251084862440837),
            'B2': self.create_pose_with_orientation(3.0673582218891755, -1.1257243512290551, 0.0, 0.0, 0.0,
                                                    0.6091855903537776, 0.7930276896208098),
            'B3': self.create_pose_with_orientation(0.8374228194003915, -1.3122654392221809, 0.0, 0.0, 0.0,
                                                    0.6614895832812627, 0.74995435275114),
            'B4': self.create_pose_with_orientation(0.8438080372981867, 0.982063535294432, 0.0, 0.0, 0.0,
                                                    0.7063817793411464, 0.7078310404431526)
        }

    # 테이블 번호 메시지를 처리하는 콜백 함수
    def table_callback(self, msg):
        table_num_msg = msg.data  # 메시지에서 데이터를 추출
        if table_num_msg in self.goal_poses:
            # 테이블 번호가 알려진 경우 해당 목표 위치로 목표 전송
            self.send_goal(self.goal_poses[table_num_msg], publish_result=True)
        else:
            # 테이블 번호가 알려지지 않은 경우 로그에 메시지 출력
            self.get_logger().info(f'Unknown table number: {table_num_msg}')

    # 위치와 방향을 포함한 PoseStamped 메시지를 생성하는 헬퍼 함수
    def create_pose_with_orientation(self, x, y, z, ox, oy, oz, ow):
        pose = PoseStamped()
        pose.header.frame_id = 'map'  # 참조 프레임을 'map'으로 설정
        pose.pose.position.x = x
        pose.pose.position.y = y
        pose.pose.position.z = z
        pose.pose.orientation.x = ox
        pose.pose.orientation.y = oy
        pose.pose.orientation.z = oz
        pose.pose.orientation.w = ow
        return pose

    # 액션 서버에 네비게이션 목표를 전송하는 함수
    def send_goal(self, pose, publish_result=False):
        self.get_logger().info('Waiting for action server...')
        # 액션 서버가 사용 가능할 때까지 대기
        self.action_client.wait_for_server()

        # 지정된 위치로 네비게이션할 목표 메시지 생성
        goal_msg = NavigateToPose.Goal()
        goal_msg.pose = pose

        # 목표 위치를 로그에 출력하고 비동기적으로 목표 전송
        self.get_logger().info(f'Sending goal to position: x={pose.pose.position.x}, y={pose.pose.position.y}')
        self._send_goal_future = self.action_client.send_goal_async(goal_msg)
        self._send_goal_future.add_done_callback(lambda future: self.goal_response_callback(future, publish_result))

    # 액션 서버의 응답을 처리하는 콜백 함수
    def goal_response_callback(self, future, publish_result):
        result = future.result()
        if result.accepted:
            # 목표가 수락되었음을 로그에 출력하고 결과 콜백 설정
            self.get_logger().info("Goal accepted!")
            result_handle = result.get_result_async()
            result_handle.add_done_callback(lambda future: self.get_result_callback(future, publish_result))
        else:
            # 목표가 거부되었음을 로그에 출력
            self.get_logger().info("Goal rejected!")

    # 목표 결과를 처리하는 콜백 함수
    def get_result_callback(self, future, publish_result):
        result = future.result()
        if publish_result:
            finished_goal_msg = Bool()
            if result.status == 4:  # 목표가 성공적으로 완료되었는지 상태를 사용하여 확인
                # 목표에 도달했음을 로그에 출력하고 결과를 발행
                self.get_logger().info('Goal reached successfully')
                finished_goal_msg.data = True
            else:
                # 목표 도달 실패를 로그에 출력하고 결과를 발행
                self.get_logger().info('Failed to reach goal')
                finished_goal_msg.data = False
            self.publisher_.publish(finished_goal_msg)
        if result.status == 4:
            # 30초 후에 초기 위치로 돌아가기 위한 타이머 시작
            threading.Timer(30.0, lambda: self.return_to_initial_position(False)).start()

    # 초기 위치로 돌아가는 함수
    def return_to_initial_position(self, publish_result):
        self.get_logger().info('Returning to initial position...')
        self.send_goal(self.initial_position, publish_result=publish_result)


# 노드를 초기화하고 스핀을 시작하는 메인 함수
def main(args=None):
    rclpy.init(args=args)  # ROS2 통신 초기화
    node = Robot()  # Robot 클래스의 인스턴스 생성
    rclpy.spin(node)  # 노드를 계속 실행하여 메시지를 수신하고 작업 수행
    node.destroy_node()  # 작업이 완료되면 노드 삭제
    rclpy.shutdown()  # ROS2 통신 종료


if __name__ == '__main__':
    main()
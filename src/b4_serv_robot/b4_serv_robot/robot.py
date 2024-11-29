# 1. ros2 launch turtlebot3_gazebo turtlebot3_world.launch.py
# 2. ros2 launch turtlebot3_navigation2 navigation2.launch.py map:=$HOME/map.yaml
# 3. ros2 run b4_serv_robot robot
# 4. ros2 topic pub --once /table_no_msg std_msgs/String "data: 'B4'"


import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from std_msgs.msg import String, Bool
from nav2_msgs.action import NavigateToPose
from rclpy.action import ActionClient
from rclpy.qos import QoSDurabilityPolicy, QoSHistoryPolicy, QoSProfile, QoSReliabilityPolicy
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
import threading
from std_srvs.srv import SetBool

from PyQt5.QtWidgets import QApplication, QWidget, QLabel, QPushButton, QVBoxLayout
from PyQt5.QtGui import QMovie, QPalette, QBrush, QPixmap
from PyQt5.QtCore import Qt, QTimer


# class RobotControlApp(QWidget):
#     def __init__(self):
#         super().__init__()
#         self.initUI()
#         self.is_moving = False  # 로봇이 이동 중인지 여부를 저장하는 변수
#         self.is_resting = False  # 로봇이 쉬고 있는 상태인지 여부를 저장하는 변수

#     def initUI(self):
#         # 윈도우 설정
#         self.setWindowTitle('로봇 제어 인터페이스')
#         self.setGeometry(100, 100, 843, 582)  # 크기를 sleep_robot.gif 크기로 변경

#         # 로봇 이미지 라벨
#         self.robot_label = QLabel(self)
#         self.robot_movie = QMovie('/home/jw7720/Downloads/sleep_robot.gif')  # 초기 배경 이미지 설정
#         self.robot_label.setMovie(self.robot_movie)
#         self.robot_movie.start()
#         self.robot_label.setAlignment(Qt.AlignCenter)

#         # 메시지 창 라벨
#         self.message_label = QLabel('메시지 창', self)
#         self.message_label.setStyleSheet("font-size: 14px; padding: 10px; background-color: rgba(255, 255, 255, 150); max-height: 100px;")
#         self.message_label.setAlignment(Qt.AlignCenter)

#         # 로봇 출발 버튼 (초기 상태)
#         self.return_button = QPushButton('로봇 출발', self)
#         self.return_button.setStyleSheet("font-size: 16px; padding: 10px;")
#         self.return_button.clicked.connect(self.on_start_button_clicked)

#         # 레이아웃 설정
#         layout = QVBoxLayout()
#         layout.addWidget(self.robot_label)
#         layout.addWidget(self.message_label)
#         layout.addWidget(self.return_button)

#         self.setLayout(layout)

# #### 복귀 버튼 생성 및 로봇 복귀 버튼 비활성화 , 출발버튼이 작동시 QTimer.singleShot(5000, self.reach_goal) 이코드로 5초동안 움직임 5000은 시간   self.reach_goal 으로 이동
#     def on_start_button_clicked(self):
#         if self.is_moving:
#             return  # 로봇이 이미 이동 중인 경우 동작하지 않음

#         # 쉬는 중일 때 출발 버튼을 누르면 카운트 다운을 무시하고 강제로 출발
#         if self.is_resting:
#             self.is_resting = False

#         self.return_button.setEnabled(False)  # 버튼 비활성화

#         # 로봇이 이동 중임을 표시
#         self.is_moving = True
#         # 버튼 클릭 시 목표로 이동 상태로 업데이트
#         self.update_status('goal_accepted')
#         # 버튼 텍스트를 '로봇 복귀 버튼'으로 변경
#         self.return_button.setText('로봇 복귀 버튼')
#         # 버튼 클릭 연결을 변경하여 복귀 동작을 수행하도록 설정
#         self.return_button.clicked.disconnect()
#         self.return_button.clicked.connect(self.on_return_button_clicked)
#         # 5초 후 목표 도착 상태로 업데이트
#         QTimer.singleShot(5000, self.reach_goal)


# ### 멈출때만 버튼이 작동하게 해줌
#     def on_return_button_clicked(self):
#         if not self.is_moving:
#             return  # 로봇이 이동 중이 아니면 동작하지 않음

#         self.return_button.setEnabled(False)  # 버튼 비활성화

#         # 원점으로 돌아가는 상태로 업데이트
#         self.return_to_initial()


# ### goal 에 도착했을시         QTimer.singleShot(5000, self.return_to_initial) 이코드 5초동안 엄춘후 복귀 움직임으로 변경  -> self.finish_movement
#     def reach_goal(self):
#         # 목표 도착 상태로 업데이트
#         self.update_status('goal_reached')
#         # 로봇 복귀 버튼 활성화
#         self.return_button.setEnabled(True)
#         # 5초 후 원점 복귀 상태로 업데이트
#         QTimer.singleShot(5000, self.return_to_initial)


# #### 원점복귀 시켜주는 함수
#     def return_to_initial(self):
#         # 원점 복귀 상태로 업데이트
#         self.update_status('return_to_initial')
#         # 5초 후 휴식 상태로 업데이트
#         QTimer.singleShot(5000, self.finish_movement)


# #### 함수는 화면 변경 함수
#     def update_status(self, status):
#         # 상태에 따라 로봇 이미지 변경
#         if status == 'goal_accepted':
#             self.message_label.setText('로봇이 이동 중입니다.')
#             self.set_movie_gif('src/b4_serv_robot/resource/move_robot.gif')
#         elif status == 'goal_reached':
#             self.message_label.setText('로봇이 목표 지점에 도착했습니다. 대기 중입니다.')
#             self.set_movie_gif('src/b4_serv_robot/resource/wait_robot.gif')
#         elif status == 'return_to_initial':
#             self.message_label.setText('로봇이 처음 위치로 돌아갑니다.')
#             self.set_movie_gif('src/b4_serv_robot/resource/return_robot.gif')
#         elif status == 'resting':
#             self.message_label.setText('로봇이 쉬고 있는 상태입니다.')
#             self.set_movie_gif('src/b4_serv_robot/resource/sleep_robot.gif')
#         else:
#             self.message_label.setText('알 수 없는 상태입니다.')


# #### gif 움직이게 해주는 함수
#     def set_movie_gif(self, gif_path):
#         # GIF를 설정하는 함수
#         self.robot_movie = QMovie(gif_path)
#         self.robot_label.setMovie(self.robot_movie)
#         self.robot_movie.start()


# #####  원점으로 도착후 출발 버튼활성화 시켜주고 , 휴식 모드로 들어가게 해주는 코드
#     def finish_movement(self):
#         self.return_button.setEnabled(True)  # 버튼 활성화
#         # 로봇이 이동을 완료하고 쉬는 상태로 전환
#         self.update_status('resting')
#         self.is_moving = False
#         self.is_resting = True
#         # 버튼을 다시 '로봇 출발'로 초기화
#         self.return_button.setText('로봇 출발')
#         self.return_button.clicked.disconnect()
#         self.return_button.clicked.connect(self.on_start_button_clicked)

# rclpy의 Node 클래스를 상속받는 Robot 클래스 정의
class Robot(Node):
    def __init__(self):
        super().__init__('robot')

        self.callback_group = ReentrantCallbackGroup()

        topic_qos = QoSProfile(
            reliability=QoSReliabilityPolicy.RELIABLE,  # 신뢰성 보장
            history=QoSHistoryPolicy.KEEP_LAST,  # 최신 데이터 유지
            depth=5,  # 최근 5개 메시지 유지
            durability=QoSDurabilityPolicy.VOLATILE  # 현재 연결된 구독자만 메시지 수신
        )

        # 테이블 번호 메시지를 수신하기 위한 구독 생성
        self.subscription = self.create_subscription(String, 'table_no_msg', self.table_callback, qos_profile=topic_qos,
                                                     callback_group=self.callback_group)

        # 목표 지점 도달 여부를 발행하기 위한 퍼블리셔 생성
        self.publisher_ = self.create_publisher(Bool, 'finished_goal', qos_profile=topic_qos,
                                                callback_group=self.callback_group)

        # 로봇에게 네비게이션 목표를 전송하기 위한 액션 클라이언트 생성
        self.action_client = ActionClient(self, NavigateToPose, 'navigate_to_pose', callback_group=self.callback_group)

        # 서비스 서버 생성
        self.srv = self.create_service(SetBool, 'come_back_srv', self.handle_come_back_request,
                                       callback_group=self.callback_group)

        # 서비스 요청 완료 후 처리 결과를 발행하기 위한 퍼블리셔 생성
        self.come_back_finished_publisher = self.create_publisher(Bool, 'come_back_finished', qos_profile=topic_qos,
                                                                  callback_group=self.callback_group)

        # 초기 위치
        self.initial_position = self.create_pose_with_orientation(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0)

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

        # 서비스 요청에 의해 초기 위치로 돌아가는지 여부를 저장하는 플래그
        self.returning_to_initial_position_from_service = False

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
        if result.status == 4 and self.returning_to_initial_position_from_service:
            # 서비스 요청으로 초기 위치에 도착했을 때만 처리 결과 발행
            come_back_finished_msg = Bool()
            come_back_finished_msg.data = True
            self.come_back_finished_publisher.publish(come_back_finished_msg)
            # 플래그 초기화
            self.returning_to_initial_position_from_service = False

    # 초기 위치로 돌아가는 함수
    def return_to_initial_position(self, publish_result, from_service=False):
        self.get_logger().info('Returning to initial position...')
        self.returning_to_initial_position_from_service = from_service
        self.send_goal(self.initial_position, publish_result=publish_result)

    def handle_come_back_request(self, request, response):
        # 로봇이 돌아오도록 요청 받았을 때
        self.get_logger().info("Processing robot comeback request.")
        self.return_to_initial_position(False, from_service=True)
        response.success = True
        response.message = "Robot comeback initiated."

        return response


# 노드를 초기화하고 스핀을 시작하는 메인 함수
def main(args=None):
    rclpy.init(args=args)  # ROS2 통신 초기화
    node = Robot()  # Robot 클래스의 인스턴스 생성
    executor = MultiThreadedExecutor()  # 멀티스레드 실행자 생성
    executor.add_node(node)

    ros_thread = threading.Thread(target=executor.spin, daemon=True)
    ros_thread.start()

    # Your main application code here (PyQt or other)
    try:
        ros_thread.join()  # Wait for the ROS thread to finish
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()
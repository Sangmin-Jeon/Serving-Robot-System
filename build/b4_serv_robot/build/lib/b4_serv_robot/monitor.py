import sys
import threading
import queue
from datetime import datetime
import re

# ROS 2 관련 라이브러리
import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.qos import (
    QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy, QoSDurabilityPolicy
)


# ROS 2 메시지 및 서비스 정의
from std_msgs.msg import String
from std_msgs.msg import Bool
from std_srvs.srv import SetBool
from b4_serv_robot_interface.srv import Order, OrderCancel
from b4_serv_robot_interface.msg import DB

# PyQt5 관련 라이브러리
from PyQt5.QtCore import Qt, QObject, pyqtSignal, QTimer, QTime
from PyQt5.QtWidgets import (
    QApplication, QMainWindow, QWidget, QVBoxLayout, QHBoxLayout,
    QLabel, QPushButton, QComboBox, QCheckBox, QGridLayout,
    QTabWidget, QTableWidget, QTableWidgetItem, QSizePolicy, QScrollArea,
)



class NODE(Node, QObject):
    message_received = pyqtSignal(Order.Request)
    info_received = pyqtSignal(str)
    move_table_received = pyqtSignal(bool)
    move_table_finished_received = pyqtSignal(bool)
    come_back_received = pyqtSignal(bool)
    finished_received = pyqtSignal(bool)

    def __init__(self):
        super().__init__('node')
        QObject.__init__(self)

        self.callback_group = ReentrantCallbackGroup()

        # order qos
        srv_qos_profile = QoSProfile(
            reliability=QoSReliabilityPolicy.RELIABLE,  # 신뢰성 보장
            history=QoSHistoryPolicy.KEEP_LAST,  # 가장 최근 메시지만 유지
            depth=1,  # 최근 1개 메시지 유지
            durability=QoSDurabilityPolicy.VOLATILE  # 현재 연결된 구독자만 메시지 수신
        )

        # robot, db qos
        qos_profile = QoSProfile(
            reliability=QoSReliabilityPolicy.RELIABLE,  # 신뢰성 보장
            history=QoSHistoryPolicy.KEEP_LAST,  # 가장 최근 메시지만 유지
            depth=5,  # 최근 5개 메시지 유지
            durability=QoSDurabilityPolicy.VOLATILE  # 현재 연결된 구독자만 메시지 수신
        )

        # 주문 확인 서비스
        self.service_server = self.create_service(
            Order,
            'order_service',
            self.order_service,
            qos_profile=srv_qos_profile,
            callback_group=self.callback_group
        )

        # 주문 취소 서비스
        self.cancel_client = self.create_client(
            OrderCancel,
            'order_cancel_service',
            qos_profile=srv_qos_profile,
            callback_group=self.callback_group)

        # DB 노드에 Topic 발행
        self.message_publisher = self.create_publisher(
            DB,
            'order_db_message',
            qos_profile=qos_profile,
            callback_group=self.callback_group)

        self.queue = queue.Queue()
        self.timer = self.create_timer(0.1, self.publish_order_message)

        # robot 노드에 Topic 발행
        self.move_robot_publisher = self.create_publisher(
            String,
            'table_no_msg',
            qos_profile=qos_profile,
            callback_group=self.callback_group)

        self.table_num = ''
        self.timer = self.create_timer(0.1, self.publish_move_robot)

        self.robot_goal_send_sub = self.create_subscription(
            String,
            'finished_goal',
            self.finished_goal_callback,
            qos_profile=qos_profile,
            callback_group=self.callback_group)

        self.robot_come_back_client = self.create_client(
            SetBool,
            'come_back_srv',
            qos_profile=srv_qos_profile,
            callback_group=self.callback_group
        )

        self.move_finished_robot_sub = self.create_subscription(
            Bool,
            'come_back_finished',
            self.come_back_finished_callback,
            qos_profile=qos_profile,
            callback_group=self.callback_group
        )

    # 주문 확인
    def order_service(self, request, response):
        try:
            # 서비스 요청 로그
            self.get_logger().info(
                f"Received service request: Table {request.table_num} with orders {request.order_info} time: {request.order_time}"
            )

            # PyQt 신호로 전달
            self.message_received.emit(request)
            self.info_received.emit(f"{request.order_time} [주문 접수] {request.table_num} 테이블: {request.order_info} ")
            self.get_logger().info(f"Order processed for table {request.table_num}.")

            response.is_order = True

            return response

        except Exception as e:
            # 예외 처리 및 응답 설정
            self.get_logger().error(f"Error while processing service request: {e}")
            response.is_order = False
            return response

    # 주문 취소
    def order_cancel(self, is_cancel):
        try:
            # 주문 취소 요청 메시지 생성
            request = OrderCancel.Request()
            request.is_cancel = is_cancel

            # 비동기 서비스 호출
            future = self.cancel_client.call_async(request)
            future.add_done_callback(self.cancel_response_callback)

            current_time = datetime.now()
            formatted_time = current_time.strftime("%Y-%m-%d %H:%M:%S")
            self.info_received.emit(f"{formatted_time} [주문 취소] ")

        except Exception as e:
            self.get_logger().error(f"Error while sending cancel request: {e}")

    # 주문 취소 응답 처리
    def cancel_response_callback(self, future):
        try:
            response = future.result()
            if response.cancel_confirm:
                self.get_logger().info("Cancel confirmed by server.")
                # self.cancel_confirmed.emit(True)
            else:
                self.get_logger().warning("Cancel not confirmed by server.")
                # self.cancel_confirmed.emit(False)
        except Exception as e:
            self.get_logger().error(f"Error in cancel response: {e}")
            # self.cancel_confirmed.emit(False)

    # 주문 정보 DB 노드에 발행
    def publish_order_message(self):
        while not self.queue.empty():
            message = self.queue.get()

            # DB 메시지 생성
            msg = DB()
            msg.order_info = message

            # 메시지 발행
            self.message_publisher.publish(msg)
            self.get_logger().info(f'Published message: {msg}')

    # 로봇으로 테이블 번호 발행, 로봇 테이블로 이동
    def publish_move_robot(self):
        if self.table_num != '':
            msg = String()  # std_msgs.msg.String 객체 생성
            msg.data = self.table_num  # 메시지 데이터에 문자열 값 할당
            # 메시지 발행
            self.move_robot_publisher.publish(msg)
            self.get_logger().info(f'Published message to robot node: {msg.data}')
            self.table_num = ''
            self.move_table_received.emit(True)

            current_time = datetime.now()
            formatted_time = current_time.strftime("%Y-%m-%d %H:%M:%S")
            self.info_received.emit(f"{formatted_time} [로봇 이동중] {self.table_num} 테이블 ")

    def finished_goal_callback(self, msg):
        self.get_logger().info(f'Received finished goal: {msg.data}')
        if msg.data == "table":
            self.move_table_finished_received.emit(True)

            current_time = datetime.now()
            formatted_time = current_time.strftime("%Y-%m-%d %H:%M:%S")
            self.info_received.emit(f"{formatted_time} [로봇 테이블 도착 완료] 음식 가져가는 중")
        else:
            self.finished_received.emit(True)
            current_time = datetime.now()
            formatted_time = current_time.strftime("%Y-%m-%d %H:%M:%S")
            self.info_received.emit(f"{formatted_time} [로봇 복귀완료] 대기중 ")

    def robot_come_back_call(self, is_call):
        try:
            # 서비스 요청 생성
            request = SetBool.Request()
            request.data = is_call  # boolean 값 설정

            # 비동기 서비스 호출
            future = self.robot_come_back_client.call_async(request)
            print(f"돌아와: {request.data}")
            future.add_done_callback(self.come_back_response_callback)
            self.come_back_received.emit(True)

            current_time = datetime.now()
            formatted_time = current_time.strftime("%Y-%m-%d %H:%M:%S")
            self.info_received.emit(f"{formatted_time} [로봇 복귀중] ")

        except Exception as e:
            print(f"Error while sending robot comeback request: {e}")

    def come_back_response_callback(self, future):
        try:
            response = future.result()

            # 응답에서 success와 message 사용
            if response.success:
                self.get_logger().info(f'Received finished robot comeback: {response.message}')
            else:
                self.get_logger().warning("Robot comeback failed.")
        except Exception as e:
            self.get_logger().error(f'Error in robot comeback response: {e}')


    def come_back_finished_callback(self, msg):
        self.get_logger().info(f'Completed finished robot comeback: {msg}')
        if msg.data:
            self.finished_received.emit(True)
            current_time = datetime.now()
            formatted_time = current_time.strftime("%Y-%m-%d %H:%M:%S")
            self.info_received.emit(f"{formatted_time} [로봇 복귀완료] 대기중 ")




# Tab 1 Content Widget (Basic)
class Tab1Content(QWidget):
    def __init__(self, node, window):
        super().__init__()
        layout = QVBoxLayout(self)
        self.node = node

        # Add MainDashboard as part of the layout in Tab 1
        self.main_dashboard = MainDashboard(self.node, window)  # Instantiate the MainDashboard class
        layout.addWidget(self.main_dashboard)  # Add MainDashboard to Tab 1

        self.setLayout(layout)

# Tab 1개로 바뀌면서 삭제
# class Tab2Content(QWidget):
#     def __init__(self):
#         super().__init__()
#         layout = QVBoxLayout(self)
#         label = QLabel("Tab 2 Content", self)
#         layout.addWidget(label)
#
#         # Add Sales Dashboard
#         self.sales_dashboard = SalesDashboard()
#         layout.addWidget(self.sales_dashboard)
#
#         self.setLayout(layout)


class Cell(QWidget):
    def __init__(self, table_number, order_details, order_time, node, dashboard, index):
        super().__init__()
        self.node = node

        self.cell_index = index
        self.table_number = table_number
        self.order_details = order_details
        self.order_time = order_time

        self.dashboard = dashboard
        self.elapsed_time = QTime(0, 0, 0)

        self.set_cell_layout()
        self.start_timer()
        self.get_move_table_finished_message()
        self.get_come_back_message()

    def set_cell_layout(self):
        screen_width = 1300
        available_height = 550
        available_width = screen_width - 40
        cell_width = available_width // 3
        cell_height = available_height


        self.setFixedSize(cell_width, cell_height)

        self.wrapper = QWidget(self)
        self.wrapper.setGeometry(0, 0, cell_width, cell_height)

        self.wrapper.setStyleSheet(
            "background-color: white;"
            "border: 2px solid #4CAF50;"  
            "border-radius: 5px;"  
            "margin: 5px;"
        )

        layout = QVBoxLayout(self.wrapper)
        layout.setAlignment(Qt.AlignTop)
        layout.setSpacing(0)
        layout.setContentsMargins(10, 10, 10, 10)

        top_layout = QHBoxLayout()
        top_layout.setSpacing(10)

        self.table_number_label = QLabel(f"테이블 {self.table_number}", self.wrapper)
        self.table_number_label.setStyleSheet(
            "background-color: blue; padding: 5px; font-size: 18px; font-weight: bold; color: white;"
            # Blue background, white text
        )
        self.table_number_label.setFixedHeight(50)
        self.table_number_label.setAlignment(Qt.AlignCenter)

        top_layout.addWidget(self.table_number_label)

        button_layout = QHBoxLayout()
        button_layout.setSpacing(5)  # 좁은 간격으로 버튼들 배치 (간격을 10에서 5로 좁힘)

        self.confirm_button = QPushButton("확인", self.wrapper)
        self.confirm_button.setStyleSheet(
            "background-color: #0d3383; color: white; font-size: 18px; font-weight: bold;")
        self.confirm_button.setFixedSize(100, 50)  # 버튼 크기 120x50으로 지정

        self.move_robot_label = QLabel("로봇 이동중", self.wrapper)
        self.move_robot_label.setStyleSheet(
            "background-color: green; color: white; font-size: 18px; font-weight: bold;"
        )
        self.move_robot_label.setFixedSize(110, 50)
        self.move_robot_label.setAlignment(Qt.AlignCenter)
        self.move_robot_label.setVisible(False)

        self.goal_robot_label = QLabel("테이블 도착", self.wrapper)
        self.goal_robot_label.setStyleSheet(
            "background-color: green; color: white; font-size: 18px; font-weight: bold;"
        )
        self.goal_robot_label.setFixedSize(110, 50)  # 수정: .setFixedSize 부분 오류 수정
        self.goal_robot_label.setAlignment(Qt.AlignCenter)
        self.goal_robot_label.setVisible(False)

        self.come_back_robot_label = QLabel("주방 복귀중", self.wrapper)
        self.come_back_robot_label.setStyleSheet(
            "background-color: green; color: white; font-size: 18px; font-weight: bold;"
        )
        self.come_back_robot_label.setFixedSize(110, 50)  # 수정: .setFixedSize 부분 오류 수정
        self.come_back_robot_label.setAlignment(Qt.AlignCenter)
        self.come_back_robot_label.setVisible(False)

        self.cancel_button = QPushButton("취소", self.wrapper)
        self.cancel_button.setStyleSheet("background-color: #cc0033; color: white; font-size: 18px; font-weight: bold;")
        self.cancel_button.setFixedSize(100, 50)  # 버튼 크기 120x50으로 지정

        button_layout.addWidget(self.confirm_button)
        button_layout.addWidget(self.move_robot_label)
        button_layout.addWidget(self.goal_robot_label)
        button_layout.addWidget(self.come_back_robot_label)
        button_layout.addWidget(self.cancel_button)

        self.confirm_button.clicked.connect(self.confirm_order)
        self.cancel_button.clicked.connect(self.cancel_order)

        top_layout.addLayout(button_layout)

        layout.addLayout(top_layout)

        time_layout = QVBoxLayout()

        # Add "주문시간" label
        self.order_time_label = QLabel("주문 시간", self.wrapper)
        self.order_time_label.setStyleSheet(
            "background-color: gray; padding: 3px; font-size: 18px; font-weight: bold; color: white;"
            # Styling for the label
        )
        self.order_time_label.setAlignment(Qt.AlignCenter)

        self.time_label = QLabel(self.convert_date_format(self.order_time), self.wrapper)
        self.time_label.setStyleSheet(
            "background-color: gray; padding: 3px; font-size: 18px; font-weight: bold; color: white;"
            # Styling for the time
        )
        self.time_label.setAlignment(Qt.AlignCenter)

        time_layout.addWidget(self.order_time_label)
        time_layout.addWidget(self.time_label)

        layout.addLayout(time_layout)

        self.timer_label = QLabel("경과시간: 00:00", self.wrapper)
        self.timer_label.setStyleSheet(
            "background-color: lightgreen; padding: 5px; font-size: 16px; color: black;"
        )
        self.timer_label.setAlignment(Qt.AlignCenter)
        layout.addWidget(self.timer_label)

        self.menu_label = QLabel(f"메뉴 목록", self.wrapper)
        self.menu_label.setStyleSheet(
            "background-color: gray; padding: 5px; font-size: 18px; font-weight: bold; color: white;"
            # Blue background, white text
        )
        self.menu_label.setFixedHeight(50)
        self.menu_label.setAlignment(Qt.AlignCenter)
        layout.addWidget(self.menu_label)

        details_layout = QVBoxLayout()
        details_layout.setSpacing(5)
        details_layout.setContentsMargins(0, 0, 0, 0)
        details_layout.setAlignment(Qt.AlignTop)

        for detail in self.order_details:
            _detail = detail.split("/")
            conv_str = _detail[0] + "   " + _detail[1] + "개" + "   " + _detail[2] + "원"
            detail_label = QLabel(conv_str, self.wrapper)
            detail_label.setFixedHeight(50)
            detail_label.setStyleSheet(
                "background-color: lightgray; font-size: 16px; color: black;" 
                "border: 1px solid #aaa;"  
                "font-weight: bold;"
            )
            detail_label.setAlignment(Qt.AlignLeft | Qt.AlignVCenter)
            details_layout.addWidget(detail_label)

        layout.addLayout(details_layout)

        self.setLayout(layout)

        size_policy = QSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
        self.setSizePolicy(size_policy)

        self.start_timer()

    def start_timer(self):
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.update_timer)
        self.timer.start(1000)

    def update_timer(self):
        self.elapsed_time = self.elapsed_time.addSecs(1)
        self.timer_label.setText(f"경과시간              {self.elapsed_time.toString('mm:ss')}")

    # 주문 확인
    def confirm_order(self):
        print(f"주문 확인: 테이블 {self.table_number}, 내역: {self.order_details}, 시간: {self.order_time}")
        # 주문 확인: 테이블 B4, 내역: ['광어+우럭 세트/1/38000', '향어회/1/35000'], 시간: 2024-11-28 14:33:08
        self.node.table_num = self.table_number

        conv_msg = self._convert_order_msg(self.table_number, self.order_details, self.order_time, False)
        self.node.queue.put(conv_msg)
        self.dashboard.get_order_cell_index(self)


        self.confirm_button.setVisible(False)
        self.move_robot_label.setVisible(True)


        # 주문 취소
    def cancel_order(self):
        print(f"주문 취소: 테이블 {self.table_number}, 내역: {self.order_details}")
        self.node.order_cancel(True)
        # 취소 버튼 클릭 시 해당 cell을 삭제
        self.dashboard.remove_cell(self)


    def _convert_order_msg(self, table_num, order_details, order_time, is_cancel):
        items = []
        current_time = datetime.now()
        formatted_time = current_time.strftime("%Y-%m-%d %H:%M:%S")

        for item in order_details:
            dump = f"{table_num}/{item}/{is_cancel}/{order_time}/{formatted_time}"
            items.append(dump)
        return items


    def convert_date_format(self, date_str):
        # 정규식으로 날짜와 시간 부분을 찾고 변환
        pattern = r'(\d{4})-(\d{2})-(\d{2}) (\d{2}):(\d{2}):(\d{2})'
        replacement = r'\1년 \2월 \3일 \4시 \5분 \6초'

        # 정규식을 사용하여 변환
        result = re.sub(pattern, replacement, date_str)

        return result

    def get_move_table_finished_message(self):
        self.node.move_table_finished_received.connect(self.move_table_finished_handler)

    def move_table_finished_handler(self):
        if self.dashboard.is_order_cell == self.cell_index:
            self.move_robot_label.setVisible(False)
            self.goal_robot_label.setVisible(True)


    def get_come_back_message(self):
        self.node.come_back_received.connect(self.come_back_handler)


    def come_back_handler(self):
        if self.dashboard.is_order_cell == self.cell_index:
            self.goal_robot_label.setVisible(False)
            self.come_back_robot_label.setVisible(True)
            print("돌아오는 중")


class MainDashboard(QWidget):
    def __init__(self, node, window):
        super().__init__()
        self.node = node
        self.is_order_cell = -1
        self.cell_count = 0

        self.get_message()
        self.get_log()
        self.finished_order()

        main_layout = QVBoxLayout(self)

        title_layout = QVBoxLayout()

        title_label = QLabel("🐟 날로먹는집 주방 모니터 🐟")
        title_label.setAlignment(Qt.AlignCenter)
        title_label.setStyleSheet("font-size: 24px; font-weight: bold; margin: 5px;")
        title_label.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Fixed)
        title_layout.addWidget(title_label)

        button_layout = QHBoxLayout()
        button_layout.addStretch(1)

        button = QPushButton("로봇 호출")
        button.setStyleSheet("font-size: 24px; font-weight: bold; margin: 5px;")

        button_layout.addWidget(button)

        button.clicked.connect(self.come_back_btn)
        title_layout.addLayout(button_layout)

        main_layout.addLayout(title_layout)

        self.grid_layout = QGridLayout()

        self.grid_layout.setAlignment(Qt.AlignTop | Qt.AlignLeft)

        self.grid_widget = QWidget()
        self.grid_widget.setLayout(self.grid_layout)

        self.scroll_area = QScrollArea(self)
        self.scroll_area.setWidgetResizable(True)
        self.scroll_area.setWidget(self.grid_widget)

        self.scroll_area.setFixedHeight(window.height() - 300)
        self.scroll_area.setFixedWidth(int(window.width() * 0.6))

        horizontal_layout = QHBoxLayout()

        horizontal_layout.addWidget(self.scroll_area)

        # Initialize layouts
        self.extra_scroll_layout = QVBoxLayout()
        self.extra_scroll_layout.setSpacing(0)
        self.extra_scroll_layout.setAlignment(Qt.AlignTop)  # Align widgets to the top

        self.extra_scroll_widget = QWidget()
        self.extra_scroll_widget.setLayout(self.extra_scroll_layout)

        extra_scroll_area = QScrollArea()
        extra_scroll_area.setWidgetResizable(True)
        extra_scroll_area.setWidget(self.extra_scroll_widget)

        # Set fixed size for the scroll area
        extra_scroll_area.setFixedHeight(window.height() - 300)
        # extra_scroll_area.setFixedWidth(int(window.width() * 0.3))

        extra_layout = QVBoxLayout()
        extra_layout.addWidget(extra_scroll_area)

        extra_layout_widget = QWidget()
        extra_layout_widget.setLayout(extra_layout)

        horizontal_layout.addWidget(extra_layout_widget)

        main_layout.addLayout(horizontal_layout)

        self.setLayout(main_layout)

        self.cells = []

    def get_message(self):
        self.node.message_received.connect(self.add_new_order)

    def get_log(self):
        self.node.info_received.connect(self.add_new_info)

    def add_new_order(self, msg):
        print(f"Received message: {msg}")

        table_number = msg.table_num
        order_details = msg.order_info
        order_time = msg.order_time

        cell = Cell(table_number, order_details, order_time, self.node, self, self.cell_count)
        self.cells.append(cell)
        self.cell_count += 1

        col = len(self.cells) - 1
        row = 0
        self.grid_layout.addWidget(cell, row, col)

        self.grid_layout.update()

    def add_new_info(self, log):
        print(f"Received log: {log}")

        # Create the label with the log text
        text_label = QLabel(log)

        style = (
            "background-color: lightgreen;"
            "color: black;"
            "border: 1px solid #aaa;"
            "padding: 5px;"
            "font-size: 14px; font-weight: bold"
        )

        if "취소" in log:
            style = style.replace("background-color: lightgreen;" , "background-color: lightcoral;")
        elif "[로봇 복귀완료]" in log:
            style = style.replace("background-color: lightgreen;", "background-color: lightblue;")
        elif "로봇" in log:
            style = style.replace("background-color: lightgreen;" , "background-color: Lavender;")


        text_label.setStyleSheet(style)


        text_label.setWordWrap(True)  # Enable word wrap to handle long text
        # text_label.setFixedWidth(int(self.width() * 0.28))  # Limit width to fit within the scroll view

        # Add the label to the scroll layout
        self.extra_scroll_layout.addWidget(text_label)


    def get_order_cell_index(self, cell):
        # if cell in self.cells:
        #     self.is_order_cell = self.cells.index(cell)
        self.is_order_cell = cell.cell_index
        print(f"Order button clicked in Cell {cell.table_number}, click index: {self.is_order_cell}, index: {cell.cell_index}")

    # Cell widget 삭제
    def remove_cell(self, cell):
        if cell in self.cells:
            self.cells.remove(cell)
            self.grid_layout.removeWidget(cell)
            cell.deleteLater()
            print(f"Cell for table {cell.table_number} has been removed.")

    # 로봇 호출
    def come_back_btn(self):
        try:
            self.node.robot_come_back_call(True)

        except Exception as e:
            self.get_logger().error(f"Error in button click callback: {e}")

    def finished_order(self):
        self.node.finished_received.connect(self.remove_finished_cell)

    def remove_finished_cell(self):
        for index, cell in enumerate(self.cells):
            if self.is_order_cell >= 0 and self.is_order_cell == cell.cell_index:
                self.remove_cell(cell)
                break




# Main GUI Class
class RootView():
    def __init__(self, node):
        self.node = node
        self.setup_layout()

    def setup_layout(self):
        # Main Window creation
        self.window = QMainWindow()
        if not self.window.objectName():
            self.window.setObjectName(u"MainWindow")
        self.window.resize(1920, 1080)

        # Central Widget Setup
        self.centralwidget = QWidget(self.window)
        self.centralwidget.setObjectName(u"centralwidget")

        # Tab Widget Creation
        self.tabWidget = QTabWidget(self.centralwidget)
        self.tabWidget.setObjectName(u"tabWidget")

        # Tab 1 Content
        self.tab1 = Tab1Content(self.node, self.window)

        # Tab 2 Content with Sales Dashboard
        # self.tab2 = Tab2Content()

        # Add Tabs to Tab Widget
        self.tabWidget.addTab(self.tab1, "주방 모니터")
        # self.tabWidget.addTab(self.tab2, "통계")

        # Set Tab Widget as central layout
        self.central_layout = QVBoxLayout(self.centralwidget)
        self.central_layout.addWidget(self.tabWidget)
        self.centralwidget.setLayout(self.central_layout)

        # Set Central Widget in Main Window
        self.window.setCentralWidget(self.centralwidget)


def main():
    # Initialize ROS 2
    rclpy.init()
    node = NODE()

    # Initialize MultiThreadedExecutor
    executor = MultiThreadedExecutor()
    executor.add_node(node)

    # Start the executor in a separate thread
    ros_thread = threading.Thread(target=executor.spin, daemon=True)
    ros_thread.start()

    # Initialize PyQt Application
    app = QApplication(sys.argv)

    # PyQt GUI 로직 (예시: RootView)
    root = RootView(node)  # RootView 클래스는 PyQt5 GUI 클래스
    root.window.show()

    # PyQt 이벤트 루프 실행
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()
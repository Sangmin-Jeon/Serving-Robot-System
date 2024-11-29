import sys
import threading
import queue
from datetime import datetime

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
from PyQt5.QtCore import Qt, QObject, pyqtSignal
from PyQt5.QtWidgets import (
    QApplication, QMainWindow, QWidget, QVBoxLayout, QHBoxLayout,
    QLabel, QPushButton, QComboBox, QCheckBox, QGridLayout,
    QTabWidget, QTableWidget, QTableWidgetItem, QSizePolicy, QScrollArea
)



class NODE(Node, QObject):
    message_received = pyqtSignal(Order.Request)  # 문자열 타입 신호 정의

    def __init__(self):
        super().__init__('node')
        QObject.__init__(self)

        self.callback_group = ReentrantCallbackGroup()

        # order qos
        srv_qos_profile = QoSProfile(
            reliability=QoSReliabilityPolicy.RELIABLE,  # 신뢰성 보장
            history=QoSHistoryPolicy.KEEP_LAST,  # 가장 최근 메시지만 유지
            depth=1,  # 깊이 설정: 1
            durability=QoSDurabilityPolicy.VOLATILE  # 휘발성 메시지
        )

        # robot, db qos
        qos_profile = QoSProfile(
            reliability=QoSReliabilityPolicy.RELIABLE,  # 신뢰성 보장
            history=QoSHistoryPolicy.KEEP_LAST,  # 가장 최근 메시지만 유지
            depth=5,  # 최근 10개 메시지 유지
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
            Bool,
            'finished_goal',  # 구독할 토픽 이름
            self.finished_goal_callback,  # 메시지를 처리할 콜백 함수
            qos_profile=qos_profile,
            callback_group=self.callback_group)

        self.robot_come_back_client = self.create_client(
            SetBool,
            'come_back_srv',
            qos_profile=srv_qos_profile,  # 올바른 인자 사용
            callback_group=self.callback_group
        )

        self.move_finished_robot_sub = self.create_subscription(
            Bool,
            'come_back_finished',
            self.come_back_finished_callback,
            qos_profile=qos_profile,  # 올바른 인자 사용
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

    # 로복으로 테이블 번호 발행
    def publish_move_robot(self):
        if self.table_num != '':
            msg = String()  # std_msgs.msg.String 객체 생성
            msg.data = self.table_num  # 메시지 데이터에 문자열 값 할당
            # 메시지 발행
            self.move_robot_publisher.publish(msg)
            self.get_logger().info(f'Published message to robot node: {msg.data}')
            self.table_num = ''

    def finished_goal_callback(self, msg):
        self.get_logger().info(f'Received finished goal: {msg.data}')

    def robot_come_back_call(self, is_call):
        try:
            # 서비스 요청 생성
            request = SetBool.Request()
            request.data = is_call  # boolean 값 설정

            # 비동기 서비스 호출
            future = self.robot_come_back_client.call_async(request)
            print(f"돌아와: {request.data}")
            future.add_done_callback(self.come_back_response_callback)

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


# Tab 2 Content Widget (Includes Sales Dashboard)
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
    def __init__(self, table_number, order_details, order_time, node, dashboard):
        super().__init__()
        self.node = node

        self.table_number = table_number
        self.order_details = order_details
        self.order_time = order_time

        self.dashboard = dashboard

        self.set_cell_layout()


    # UI layout
    def set_cell_layout(self):
        # Calculate size dynamically based on screen size and design
        screen_width = 1300  # Example screen width (adjust as needed)
        available_height = self.dashboard.scroll_area.height() - 20
        available_width = screen_width - 40  # Subtract margins and padding
        cell_width = available_width // 3  # Divide by 5 for 5 cells per row
        cell_height = available_height  # Adjust the height ratio (1.5 for taller cells)

        # Set fixed size for the cell
        self.setFixedSize(cell_width, cell_height)

        # Create a wrapper for the cell to apply border to it
        self.wrapper = QWidget(self)  # Create a wrapper widget
        self.wrapper.setGeometry(0, 0, cell_width, cell_height)  # Match the size of the cell

        # Set the style for the wrapper widget (border, padding, etc.)
        self.wrapper.setStyleSheet(
            "border: 2px solid #4CAF50;"  # Green border for the wrapper
            "border-radius: 5px;"  # Optional: rounded corners for the wrapper
            "margin: 5px;"  # External margin around the wrapper
        )

        # Create a vertical layout for the cell
        layout = QVBoxLayout(self.wrapper)  # Set layout to the wrapper

        # Labels for table number and order details
        self.table_number_label = QLabel(f"테이블 {self.table_number}", self.wrapper)

        # Join the order details list into a single string with line breaks
        order_details_str = "\n".join(self.order_details)  # Display list as multiline string
        self.order_details_label = QLabel(f"{order_details_str}", self.wrapper)

        font = self.order_details_label.font()
        font.setBold(True)
        self.order_details_label.setFont(font)

        # Set the style for the table number label (Blue background for the table number)
        self.table_number_label.setStyleSheet(
            "background-color: blue; padding: 5px; font-size: 18px; color: white;"  # Blue background, white text
        )

        # Set height for the table number label
        self.table_number_label.setFixedHeight(50)

        # Center align the text in the label
        self.table_number_label.setAlignment(Qt.AlignCenter)

        # Set the style for the order details label (Gray background for the order details)
        self.order_details_label.setStyleSheet(
            "background-color: lightgray; padding: 5px; font-size: 14px; color: black;"  # Gray background, black text
        )

        # Set height for the order details label
        self.order_details_label.setAlignment(Qt.AlignLeft)

        # Create buttons
        self.confirm_button = QPushButton("확인", self.wrapper)
        self.cancel_button = QPushButton("취소", self.wrapper)

        # Set button actions (connect buttons to their corresponding methods)
        self.confirm_button.clicked.connect(self.confirm_order)
        self.cancel_button.clicked.connect(self.cancel_order)

        # Create a horizontal layout for the buttons
        button_layout = QHBoxLayout()
        button_layout.addWidget(self.confirm_button)
        button_layout.addWidget(self.cancel_button)

        # Add labels and button layout to the cell layout
        layout.addWidget(self.table_number_label)
        layout.addWidget(self.order_details_label)
        layout.addLayout(button_layout)

        # Set the layout for the QWidget (cell)
        self.setLayout(layout)

        # Set size policy for dynamic resizing
        size_policy = QSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
        self.setSizePolicy(size_policy)

    # 주문 확인
    def confirm_order(self):
        print(f"주문 확인: 테이블 {self.table_number}, 내역: {self.order_details}, 시간: {self.order_time}")
        # 주문 확인: 테이블 B4, 내역: ['광어+우럭 세트/1/38000', '향어회/1/35000'], 시간: 2024-11-28 14:33:08
        self.node.table_num = self.table_number

        conv_msg = self._convert_order_msg(self.table_number, self.order_details, self.order_time, False)
        self.node.queue.put(conv_msg)

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


class MainDashboard(QWidget):
    def __init__(self, node, window):
        super().__init__()
        self.node = node

        # Main layout for the entire widget
        main_layout = QVBoxLayout(self)

        # Title layout
        title_layout = QVBoxLayout()

        # Add a title at the top
        title_label = QLabel("🐟 날로먹는집 주방 모니터 🐟")
        title_label.setAlignment(Qt.AlignCenter)  # Center the title
        title_label.setStyleSheet("font-size: 24px; font-weight: bold; margin: 5px;")
        title_label.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Fixed)  # Let the label expand vertically as needed
        title_layout.addWidget(title_label)  # Add the title to the title_layout

        # Create a horizontal layout for the button
        button_layout = QHBoxLayout()
        button_layout.addStretch(1)  # This will push the button to the right

        # Create the button
        button = QPushButton("로봇 호출")
        button.setStyleSheet("font-size: 24px; font-weight: bold; margin: 5px;")
        # Add the button to the button layout
        button_layout.addWidget(button)

        button.clicked.connect(self.come_back_btn)
        title_layout.addLayout(button_layout)

        # Add the title_layout to the main layout
        main_layout.addLayout(title_layout)
        # Function to retrieve messages (implementation assumed elsewhere)
        self.get_message()

        # Create a QGridLayout for the cells
        self.grid_layout = QGridLayout()

        # Set alignment for the entire grid layout to the top-left corner
        self.grid_layout.setAlignment(Qt.AlignTop | Qt.AlignLeft)

        # Create a QWidget to hold the grid layout (for scrollable area)
        self.grid_widget = QWidget()
        self.grid_widget.setLayout(self.grid_layout)

        # Create the QScrollArea to allow scrolling
        self.scroll_area = QScrollArea(self)
        self.scroll_area.setWidgetResizable(True)  # Enable auto-resizing of widget
        self.scroll_area.setWidget(self.grid_widget)

        # Set height and width for the scroll area
        self.scroll_area.setFixedHeight(window.height() - 300)
        self.scroll_area.setFixedWidth(int(window.width() * 0.6))

        # Create a horizontal layout to hold both scroll areas side by side
        horizontal_layout = QHBoxLayout()

        # Add the main scroll area to the horizontal layout
        horizontal_layout.addWidget(self.scroll_area)

        # Create a QWidget to hold both the button and extra_scroll_area
        extra_layout_widget = QWidget()
        extra_layout = QVBoxLayout(extra_layout_widget)

        # Additional scroll view setup for extra content
        self.extra_scroll_layout = QVBoxLayout()

        self.extra_scroll_widget = QWidget()
        self.extra_scroll_widget.setLayout(self.extra_scroll_layout)

        extra_scroll_area = QScrollArea()
        extra_scroll_area.setWidgetResizable(True)
        extra_scroll_area.setWidget(self.extra_scroll_widget)

        # Fixed height and width for the additional scroll area
        extra_scroll_area.setFixedHeight(window.height() - 300)
        extra_scroll_area.setFixedWidth(int(window.width() * 0.3))  # 30% of the window width

        # Add extra_scroll_area to the extra layout (below the button)
        extra_layout.addWidget(extra_scroll_area)

        # Add the QWidget holding the button and extra_scroll_area to the horizontal layout (on the right)
        horizontal_layout.addWidget(extra_layout_widget)

        # Add the horizontal layout to the main layout
        main_layout.addLayout(horizontal_layout)

        # Set the layout for the main widget
        self.setLayout(main_layout)

        # Initialize cell list (empty at first)
        self.cells = []

    def get_message(self):
        self.node.message_received.connect(self.add_new_order)

    def add_new_order(self, msg):
        print(f"Received message: {msg}")

        # Directly use the order_info as a list
        table_number = msg.table_num
        order_details = msg.order_info  # msg.order_info is already a list
        order_time = msg.order_time

        # Create a new Cell widget and add it to the layout
        cell = Cell(table_number, order_details, order_time, self.node, self)
        self.cells.append(cell)  # Add new cell to the list

        # Add the new cell to the grid layout (always in row 0)
        col = len(self.cells) - 1  # Set the column to the current cell index
        row = 0  # Always set row to 0 to keep adding in the same row
        self.grid_layout.addWidget(cell, row, col)

        # Optionally, adjust the layout to ensure the grid is resized properly
        self.grid_layout.update()

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
            # Call the method robot_come_back_call with True
            self.node.robot_come_back_call(True)

        except Exception as e:
            self.get_logger().error(f"Error in button click callback: {e}")



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
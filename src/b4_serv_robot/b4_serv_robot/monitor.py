import sys
import threading
import queue

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile
from std_msgs.msg import String
from b4_serv_robot_interface.srv import OrderCancel
from b4_serv_robot_interface.srv import Order
from rclpy.executors import MultiThreadedExecutor

from PyQt5.QtWidgets import QApplication, QMainWindow, QComboBox, QVBoxLayout, QWidget, QCheckBox, QHBoxLayout, QLabel, QTabWidget, QPushButton
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
import matplotlib.pyplot as plt

from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QTableWidget, QTableWidgetItem, QPushButton, QHBoxLayout
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QGridLayout
from PyQt5.QtWidgets import QTableWidgetItem, QPushButton, QHBoxLayout, QWidget
from PyQt5.QtWidgets import QSizePolicy

# from PySide2.QtCore import *
# from PySide2.QtWidgets import *
from PyQt5.QtCore import QObject, pyqtSignal

class NODE(Node, QObject):
    message_received = pyqtSignal(Order.Request)  # 문자열 타입 신호 정의

    def __init__(self):
        super().__init__('node')
        QObject.__init__(self)

        # 주문 확인 서비스
        self.service_server = self.create_service(Order, 'order_service', self.order_service)

        # 주문 취소 서비스
        self.cancel_client = self.create_client(OrderCancel, 'order_cancel_service')

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



# Tab 1 Content Widget (Basic)
class Tab1Content(QWidget):
    def __init__(self, node):
        super().__init__()
        layout = QVBoxLayout(self)
        self.node = node

        # Add MainDashboard as part of the layout in Tab 1
        self.main_dashboard = MainDashboard(self.node)  # Instantiate the MainDashboard class
        layout.addWidget(self.main_dashboard)  # Add MainDashboard to Tab 1

        # Add a label to Tab 1
        label = QLabel("Tab 1 Content", self)
        layout.addWidget(label)

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
    def __init__(self, table_number, order_details, node):
        super().__init__()
        self.node = node

        self.table_number = table_number
        self.order_details = order_details

        # Calculate size dynamically based on screen size and design
        screen_width = 1366  # Example screen width (adjust as needed)
        available_width = screen_width - 40  # Subtract margins and padding
        cell_width = available_width // 5  # Divide by 5 for 5 cells per row
        cell_height = int(cell_width * 1.3)  # Increased height ratio to 1.3

        # Set fixed size for the cell
        self.setFixedSize(cell_width, cell_height)

        # Create a wrapper for the cell to apply border to it
        self.wrapper = QWidget(self)  # Create a wrapper widget
        self.wrapper.setGeometry(0, 0, cell_width, cell_height)  # Match the size of the cell

        # Set the style for the wrapper widget (border, padding, etc.)
        self.wrapper.setStyleSheet(
            "border: 2px solid #4CAF50;"  # Green border for the wrapper
            "border-radius: 5px;"          # Optional: rounded corners for the wrapper
            "margin: 5px;"                 # External margin around the wrapper
        )

        # Create a vertical layout for the cell
        layout = QVBoxLayout(self.wrapper)  # Set layout to the wrapper

        # Labels for table number and order details
        self.table_number_label = QLabel(f"테이블 {table_number}", self.wrapper)

        # Join the order details list into a single string with line breaks
        order_details_str = "\n".join(order_details)  # Display list as multiline string
        self.order_details_label = QLabel(f"{order_details_str}", self.wrapper)

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

    def confirm_order(self):
        print(f"주문 확인: 테이블 {self.table_number}, 내역: {self.order_details}")
        #self.node.queue.put(f"주문 확인: 테이블 {self.table_number}, 내역: {self.order_details}")

    def cancel_order(self):
        print(f"주문 취소: 테이블 {self.table_number}, 내역: {self.order_details}")
        self.node.order_cancel(True)




class MainDashboard(QWidget):
    def __init__(self, node):
        super().__init__()
        self.node = node
        # Main layout for the dashboard
        main_layout = QVBoxLayout(self)
        self.get_message()

        # Create a QGridLayout
        self.grid_layout = QGridLayout()

        # Set alignment for the entire grid layout to the top-left corner
        self.grid_layout.setAlignment(Qt.AlignTop | Qt.AlignLeft)

        # Add the grid layout to the main layout
        main_layout.addLayout(self.grid_layout)

        # Set the layout of the main widget
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

        # Create a new Cell widget and add it to the layout
        cell = Cell(table_number, order_details, self.node)
        self.cells.append(cell)  # Add new cell to the list

        # Add the new cell to the grid layout
        row = len(self.cells) // 5  # Move to next row every 5 cells
        col = len(self.cells) % 5
        self.grid_layout.addWidget(cell, row, col)

        # Optionally, adjust the layout to ensure the grid is resized properly
        self.grid_layout.update()


# Main GUI Class
class RootView():
    def __init__(self, node):
        self.node = node
        self.setupUi()

    def setupUi(self):
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
        self.tab1 = Tab1Content(self.node)

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


# Main function to start ROS2 node and GUI
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
    root = RootView(node)
    root.window.show()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()
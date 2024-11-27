import sys
import threading
import queue

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile
from std_msgs.msg import String
from b4_serv_robot_interface.srv import Order


from PyQt5.QtWidgets import QApplication, QMainWindow, QComboBox, QVBoxLayout, QWidget, QCheckBox, QHBoxLayout, QLabel, QTabWidget, QPushButton
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
import matplotlib.pyplot as plt

from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QTableWidget, QTableWidgetItem, QPushButton, QHBoxLayout
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QGridLayout
from PyQt5.QtWidgets import QTableWidgetItem, QPushButton, QHBoxLayout, QWidget
from PyQt5.QtWidgets import QSizePolicy

# from .MonitorView.salesDashboard import SalesDashboard

class NODE(Node):
    def __init__(self):
        super().__init__('node')

        qos_profile = QoSProfile(depth=5)
        self.message_publisher = self.create_publisher(String, 'message', qos_profile)

        self.queue = queue.Queue()
        self.timer = self.create_timer(0.1, self.publish_message)

        self.service_server = self.create_service(Order, 'order_service', self.handle_service)

    def publish_message(self):
        while not self.queue.empty():
            message = self.queue.get()
            msg = String()
            msg.data = message
            self.message_publisher.publish(msg)
            self.get_logger().info(f'Published message: {message}')

    def handle_service(self, request, response):
        self.get_logger().info(f"Received service request: Table {request.table_num} with orders {request.order_info} time: {request.order_time}")

        # 예시: 주문이 처리되면 is_order를 True로 설정
        if request.table_num and len(request.order_info) > 0:
            response.is_order = True  # 주문이 존재하고 테이블 번호가 있으면 True로 응답
            self.get_logger().info(f"Order processed for table {request.table_num}.")
        else:
            response.is_order = False  # 테이블 번호 또는 주문 내용이 비어 있으면 False로 응답
            self.get_logger().info("Invalid order request.")

        return response


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
class Tab2Content(QWidget):
    def __init__(self):
        super().__init__()
        layout = QVBoxLayout(self)
        label = QLabel("Tab 2 Content", self)
        layout.addWidget(label)

        # Add Sales Dashboard
        self.sales_dashboard = SalesDashboard()
        layout.addWidget(self.sales_dashboard)

        self.setLayout(layout)

class SalesDashboard(QWidget):
    def __init__(self):
        super().__init__()

        # Main layout for the dashboard
        main_layout = QVBoxLayout(self)

        # Back button (Currently does nothing)
        self.back_button = QPushButton("돌아가기")
        self.back_button.clicked.connect(self.go_back)
        main_layout.addWidget(self.back_button)

        # Daily Sales Chart
        self.daily_sales_canvas = self.create_bar_chart([100, 200, 150], ["11/26", "4/27", "11/28"], "일일 매출")
        main_layout.addWidget(self.daily_sales_canvas)

        # Monthly Sales Chart with ComboBox
        month_selection_layout = QHBoxLayout()
        self.month_combo = QComboBox()
        self.month_combo.addItems(["11월", "12월"])
        month_selection_layout.addWidget(self.month_combo)
        main_layout.addLayout(month_selection_layout)
        self.month_sales_canvas = self.create_bar_chart([300, 400, 350], ["11/26", "11/27", "11/28"], "월별 매출")
        main_layout.addWidget(self.month_sales_canvas)

        # Menu Sales Chart with ComboBox
        menu_selection_layout = QHBoxLayout()
        self.menu_combo = QComboBox()
        self.menu_combo.addItems(["메뉴1", "메뉴2", "메뉴3", "메뉴4", "메뉴5"])
        menu_selection_layout.addWidget(self.menu_combo)
        main_layout.addLayout(menu_selection_layout)
        self.menu_sales_canvas = self.create_bar_chart([120, 220], ["11/26", "11/27"], "메뉴 매출")
        main_layout.addWidget(self.menu_sales_canvas)

        # Checkboxes for daily menu selection
        self.menu_checkboxes_layout = QVBoxLayout()
        self.menu_checkboxes = []
        for i in range(1, 6):
            checkbox = QCheckBox(f"메뉴{i}")
            self.menu_checkboxes.append(checkbox)
            self.menu_checkboxes_layout.addWidget(checkbox)
        main_layout.addLayout(self.menu_checkboxes_layout)

        self.setLayout(main_layout)

    def create_bar_chart(self, data, labels, title):
        # Create a bar chart
        figure, ax = plt.subplots()
        ax.bar(labels, data)
        ax.set_title(title)

        canvas = FigureCanvas(figure)
        return canvas

    def go_back(self):
        # Placeholder for "Back" button functionality
        pass


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

        # Create a vertical layout for the cell
        layout = QVBoxLayout(self)

        # Labels for table number and order details
        self.table_number_label = QLabel(f"테이블 {table_number}", self)
        self.order_details_label = QLabel(f"주문 내역: {order_details}", self)

        # Set the style for the table number label
        self.table_number_label.setStyleSheet(
            "background-color: lightgray; padding: 5px; font-size: 18px;"  # Set font size here
        )

        # Set height for the table number label
        self.table_number_label.setFixedHeight(50)

        # Center align the text in the label
        self.table_number_label.setAlignment(Qt.AlignCenter)

        # Create buttons
        self.confirm_button = QPushButton("확인", self)
        self.cancel_button = QPushButton("취소", self)

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

        # Set the style for the cell (border, padding, etc.)
        self.setStyleSheet(
            "border: 2px solid #4CAF50;"  # Green border
            "border-radius: 5px;"  # Rounded corners (optional)
            "margin: 0px;"  # Ensure no external margin
            "padding: 0px;"  # Remove internal padding
        )

        # Set size policy for dynamic resizing
        size_policy = QSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
        self.setSizePolicy(size_policy)


    def confirm_order(self):
        print(f"주문 확인: 테이블 {self.table_number}, 내역: {self.order_details}")
        self.node.queue.put(f"주문 확인: 테이블 {self.table_number}, 내역: {self.order_details}")
        self.lineEdit.clear()

    def cancel_order(self):
        print(f"주문 취소: 테이블 {self.table_number}, 내역: {self.order_details}")


class MainDashboard(QWidget):
    def __init__(self, node):
        super().__init__()
        self.node = node
        # Main layout for the dashboard
        main_layout = QVBoxLayout(self)

        # Create a QGridLayout
        grid_layout = QGridLayout()

        # Set alignment for the entire grid layout to the top-left corner
        grid_layout.setAlignment(Qt.AlignTop | Qt.AlignLeft)

        # Fill the grid with dummy data using the Cell class
        dummy_data = [
            [1, "오믈렛"],
            [2, "라면"],
            [3, "햄버거"],
            [4, "피자"],

        ]

        row, col = 0, 0
        for table_number, order_details in dummy_data:
            cell = Cell(table_number, order_details, self.node)  # Assuming you have Cell class set up
            grid_layout.addWidget(cell, row, col)
            col += 1
            if col > 4:  # If 5 cells are placed in a row, move to the next row
                col = 0
                row += 1

        # Add the grid layout to the main layout
        main_layout.addLayout(grid_layout)

        # Set the layout of the main widget
        self.setLayout(main_layout)



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
        self.tab2 = Tab2Content()

        # Add Tabs to Tab Widget
        self.tabWidget.addTab(self.tab1, "주방 모니터")
        self.tabWidget.addTab(self.tab2, "통계")

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
    ros_thread = threading.Thread(target=lambda: rclpy.spin(node), daemon=True)
    ros_thread.start()

    # Initialize PyQt Application
    app = QApplication(sys.argv)
    root = RootView(node)
    root.window.show()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()
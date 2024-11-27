import sys
import threading
import queue

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile
from std_msgs.msg import String

from PyQt5.QtWidgets import QApplication, QMainWindow, QComboBox, QVBoxLayout, QWidget, QCheckBox, QHBoxLayout, QLabel, QTabWidget, QPushButton
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
import matplotlib.pyplot as plt

from PyQt5.QtWidgets import QApplication, QMainWindow, QVBoxLayout, QWidget, QTableWidget, QTableWidgetItem
from PyQt5.QtCore import Qt

# from .MonitorView.salesDashboard import SalesDashboard


# ROS2 Node class for publishing messages
class NODE(Node):
    def __init__(self):
        super().__init__('node')
        qos_profile = QoSProfile(depth=5)
        self.message_publisher = self.create_publisher(String, 'message', qos_profile)

        self.queue = queue.Queue()
        self.timer = self.create_timer(0.1, self.publish_message)

    def publish_message(self):
        while not self.queue.empty():
            message = self.queue.get()
            msg = String()
            msg.data = message
            self.message_publisher.publish(msg)
            self.get_logger().info(f'Published message: {message}')


# Tab 1 Content Widget (Basic)
class Tab1Content(QWidget):
    def __init__(self):
        super().__init__()
        layout = QVBoxLayout(self)

        # Add a label to Tab 1
        label = QLabel("Tab 1 Content", self)
        layout.addWidget(label)

        # Add MainDashboard as part of the layout in Tab 1
        self.main_dashboard = MainDashboard()  # Instantiate the MainDashboard class
        layout.addWidget(self.main_dashboard)  # Add MainDashboard to Tab 1

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


class Cell:
    def __init__(self, data):
        # Create a table item for each cell's data
        self.item = QTableWidgetItem(data)
        self.item.setTextAlignment(Qt.AlignCenter)

    def get_item(self):
        return self.item


class MainDashboard(QWidget):
    def __init__(self):
        super().__init__()

        # Main layout for the dashboard
        main_layout = QVBoxLayout(self)

        # Create a QTableWidget
        self.table_widget = QTableWidget()

        # Set the number of rows and columns (5 rows, 3 columns)
        self.table_widget.setRowCount(5)
        self.table_widget.setColumnCount(3)

        # Set the headers for the columns
        self.table_widget.setHorizontalHeaderLabels(["Column 1", "Column 2", "Column 3"])

        # Fill the grid with dummy data using the Cell class
        dummy_data = [
            ["Row 1, Col 1", "Row 1, Col 2", "Row 1, Col 3"],
            ["Row 2, Col 1", "Row 2, Col 2", "Row 2, Col 3"],
            ["Row 3, Col 1", "Row 3, Col 2", "Row 3, Col 3"],
            ["Row 4, Col 1", "Row 4, Col 2", "Row 4, Col 3"],
            ["Row 5, Col 1", "Row 5, Col 2", "Row 5, Col 3"]
        ]

        # Populate the table with dummy data
        for row_idx, row_data in enumerate(dummy_data):
            for col_idx, data in enumerate(row_data):
                cell = Cell(data)
                self.table_widget.setItem(row_idx, col_idx, cell.get_item())

        # Add the table widget to the layout
        main_layout.addWidget(self.table_widget)

        # Set the layout of the main widget
        self.setLayout(main_layout)




# Main GUI Class
class GUI():
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
        self.tab1 = Tab1Content()

        # Tab 2 Content with Sales Dashboard
        self.tab2 = Tab2Content()

        # Add Tabs to Tab Widget
        self.tabWidget.addTab(self.tab1, "Tab 1")
        self.tabWidget.addTab(self.tab2, "Tab 2")

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
    gui = GUI(node)
    gui.window.show()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()

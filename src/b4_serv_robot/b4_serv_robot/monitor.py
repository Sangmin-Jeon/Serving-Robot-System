import sys
import threading
import queue
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile

from PySide2.QtCore import *
from PySide2.QtGui import *
from PySide2.QtWidgets import *

from std_msgs.msg import String

from PyQt5.QtWidgets import QMainWindow, QWidget, QLineEdit, QPushButton, QStatusBar, QGridLayout
from PyQt5.QtCore import QRect
from PyQt5.QtWidgets import QApplication, QMainWindow, QWidget, QLineEdit, QPushButton, QTabWidget, QVBoxLayout, QHBoxLayout, QLabel


class NODE(Node):
    def __init__(self):
        super().__init__('node')
        qos_profile = QoSProfile(depth=5)
        self.message_publisher = self.create_publisher(String, 'message', qos_profile)

        self.queue = queue.Queue()
        self.timer = self.create_timer(0.1, self.publish_message)

    def publish_message(self):
        while self.queue:
            message = self.queue.get()
            msg = String()
            msg.data = message
            self.message_publisher.publish(msg)
            self.get_logger().info(f'Published message: {message}')


class Tab1Content(QWidget):
    def __init__(self):
        super().__init__()
        layout = QVBoxLayout(self)
        label = QLabel("Tab 1 Content", self)
        layout.addWidget(label)
        self.setLayout(layout)

class Tab2Content(QWidget):
    def __init__(self):
        super().__init__()
        layout = QVBoxLayout(self)
        label = QLabel("Tab 2 Content", self)
        layout.addWidget(label)
        self.setLayout(layout)


class GUI():
    def __init__(self, node):
        self.node = node
        self.setupUi()

    def setupUi(self):
        # Main Window 생성
        self.window = QMainWindow()
        if not self.window.objectName():
            self.window.setObjectName(u"MainWindow")
        self.window.resize(1920, 1080)

        # 중앙 위젯 설정
        self.centralwidget = QWidget(self.window)
        self.centralwidget.setObjectName(u"centralwidget")

        # Tab Widget 생성
        self.tabWidget = QTabWidget(self.centralwidget)
        self.tabWidget.setObjectName(u"tabWidget")

        # Tab 1 생성 (Tab1Content 클래스에서 관리)
        self.tab1 = Tab1Content()

        # Tab 2 생성 (Tab2Content 클래스에서 관리)
        self.tab2 = Tab2Content()

        # Tab Widget에 탭들 추가
        self.tabWidget.addTab(self.tab1, "Tab 1")
        self.tabWidget.addTab(self.tab2, "Tab 2")

        # Tab Widget을 중앙 위젯에 배치
        self.central_layout = QVBoxLayout(self.centralwidget)
        self.central_layout.addWidget(self.tabWidget)
        self.centralwidget.setLayout(self.central_layout)

        # 중앙 위젯을 Main Window에 설정
        self.window.setCentralWidget(self.centralwidget)


    def button_clicked(self):
        # 버튼 클릭 시 LineEdit의 텍스트 처리
        self.message = self.lineEdit.text()
        self.node.queue.put(self.message)
        self.lineEdit.clear()

def main():
    rclpy.init()
    node = NODE()
    ros_thread = threading.Thread(target=lambda: rclpy.spin(node), daemon=True)
    ros_thread.start()

    app = QApplication(sys.argv)
    gui = GUI(node)
    gui.window.show()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()
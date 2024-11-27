import sys
import threading
import queue
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile
from rclpy.executors import MultiThreadedExecutor
from datetime import datetime

from PyQt5.QtWidgets import (QApplication, QWidget, QPushButton, QLabel, QVBoxLayout,
                             QHBoxLayout, QFrame, QTableWidget, QTableWidgetItem, QGridLayout, QGroupBox, QMessageBox)
from PyQt5.QtGui import QPixmap
from PyQt5.QtCore import Qt, QMetaObject, Q_ARG, QTimer

from std_msgs.msg import String
from b4_serv_robot_interface.srv import Order

class GUI(QWidget):
    def __init__(self, node):
        super().__init__()
        self.node = node
        self.order_data = {}
        self.initUI()

    def initUI(self):
        self.setWindowTitle('주문 관리 시스템')
        main_layout = QVBoxLayout()
        main_layout.addLayout(self.createTopLayout())
        main_layout.addLayout(self.createContentLayout())
        self.setLayout(main_layout)
        self.resize(1000, 700)

    def createTopLayout(self):
        top_layout = QHBoxLayout()
        top_layout.setContentsMargins(0, 0, 0, 20)

        table_group_box = QGroupBox()
        table_layout = QVBoxLayout()
        self.table_label = QLabel('B4', alignment=Qt.AlignCenter)
        self.table_label.setStyleSheet("font-size: 16px; font-weight: bold;")
        table_layout.addWidget(self.table_label)
        table_group_box.setLayout(table_layout)
        table_group_box.setFixedWidth(100)
        top_layout.addWidget(table_group_box)

        shop_label = QLabel('  🐟날로먹는집🐟')
        shop_label.setStyleSheet("font-size: 24px; font-weight: bold;")
        top_layout.addWidget(shop_label)

        return top_layout

    def createContentLayout(self):
        content_layout = QHBoxLayout()
        content_layout.addWidget(self.createMenuWidget(), stretch=3)
        content_layout.addWidget(self.createSeparator())
        content_layout.addLayout(self.createOrderLayout(), stretch=1)
        return content_layout

    def createMenuWidget(self):
        menu_layout = QVBoxLayout()
        grid_layout = QGridLayout()
        self.menu_buttons = {
            '방어회': {'price': 50000, 'image': 'src/b4_serv_robot/resource/Bang.jpg'},
            '향어회': {'price': 35000, 'image': 'src/b4_serv_robot/resource/Hyang.jpg'},
            '광어+우럭 세트': {'price': 38000, 'image': 'src/b4_serv_robot/resource/GW.jpg'},
            '매운탕': {'price': 10000, 'image': 'src/b4_serv_robot/resource/Mae.jpg'},
            '소주': {'price': 5000, 'image': 'src/b4_serv_robot/resource/Han.jpeg'}
        }

        positions = [(0, 0), (0, 1), (0, 2), (1, 0), (1, 1)]
        for position, (menu_name, menu_info) in zip(positions, self.menu_buttons.items()):
            grid_layout.addLayout(self.createMenuItemLayout(menu_name, menu_info), *position)

        menu_layout.addLayout(grid_layout)
        menu_layout_widget = QWidget()
        menu_layout_widget.setLayout(menu_layout)
        return menu_layout_widget

    def createMenuItemLayout(self, menu_name, menu_info):
        item_layout = QVBoxLayout()

        image_label = QLabel(self)
        pixmap = QPixmap(menu_info['image']).scaled(200, 200, Qt.KeepAspectRatio, Qt.SmoothTransformation)
        image_label.setPixmap(pixmap)
        image_label.setAlignment(Qt.AlignCenter)
        item_layout.addWidget(image_label)

        item_label = QLabel(f'{menu_name}\n{menu_info["price"]:,.0f}원', alignment=Qt.AlignCenter)
        item_label.setStyleSheet("font-size: 20px;")
        item_layout.addWidget(item_label)

        button_layout = QHBoxLayout()
        add_button = QPushButton('+', clicked=lambda _, name=menu_name: self.addItem(name))
        add_button.setStyleSheet("background-color: #0d3383; color: white; font-size: 18px; font-weight: bold;")
        button_layout.addWidget(add_button)

        remove_button = QPushButton('-', clicked=lambda _, name=menu_name: self.removeItem(name))
        remove_button.setStyleSheet("background-color: #cc0033; color: white; font-size: 18px; font-weight: bold;")
        button_layout.addWidget(remove_button)

        item_layout.addLayout(button_layout)
        return item_layout

    def createSeparator(self):
        separator = QFrame()
        separator.setFrameShape(QFrame.VLine)
        separator.setFrameShadow(QFrame.Sunken)
        return separator

    def createOrderLayout(self):
        order_layout = QVBoxLayout()

        self.order_label = QLabel('주문 내역')
        self.order_label.setStyleSheet("font-size: 18px; font-weight: bold;")
        order_layout.addWidget(self.order_label)

        self.order_table = QTableWidget()
        self.order_table.setEditTriggers(QTableWidget.NoEditTriggers)
        self.order_table.verticalHeader().setVisible(False)
        self.order_table.setColumnCount(3)
        self.order_table.setHorizontalHeaderLabels(['메뉴명', '수량', '금액'])
        self.order_table.setColumnWidth(0, 150)
        self.order_table.setFixedWidth(400)
        self.order_table.horizontalHeader().setStretchLastSection(True)
        order_layout.addWidget(self.order_table)

        self.total_label = QLabel('총 금액: 0원')
        self.total_label.setStyleSheet("font-size: 17px; font-weight: bold;")
        order_layout.addWidget(self.total_label)

        button_layout = QHBoxLayout()
        self.order_button = QPushButton('주문', clicked=self.placeOrder)
        button_layout.addWidget(self.order_button)
        self.cancel_button = QPushButton('취소', clicked=self.cancelOrder)
        button_layout.addWidget(self.cancel_button)

        order_layout.addLayout(button_layout)
        return order_layout

    def addItem(self, menu_name):
        if menu_name in self.order_data:
            self.order_data[menu_name]['quantity'] += 1
        else:
            self.order_data[menu_name] = {'quantity': 1, 'price': self.menu_buttons[menu_name]['price']}
        self.updateOrderList()

    def removeItem(self, menu_name):
        if menu_name in self.order_data:
            if self.order_data[menu_name]['quantity'] > 1:
                self.order_data[menu_name]['quantity'] -= 1
            else:
                del self.order_data[menu_name]
        self.updateOrderList()

    def updateOrderList(self):
        self.order_table.setRowCount(0)
        total_price = 0
        for menu_name, info in self.order_data.items():
            quantity = info['quantity']
            price = info['price'] * quantity
            total_price += price

            row_position = self.order_table.rowCount()
            self.order_table.insertRow(row_position)
            self.order_table.setItem(row_position, 0, self.createTableItem(menu_name))
            self.order_table.setItem(row_position, 1, self.createTableItem(str(quantity)))
            self.order_table.setItem(row_position, 2, self.createTableItem(f'{price:,.0f}원'))

        self.total_label.setText(f'총 금액: {total_price:,.0f}원')

    def createTableItem(self, text):
        item = QTableWidgetItem(text)
        item.setTextAlignment(Qt.AlignCenter)
        font = item.font()
        font.setBold(True)
        item.setFont(font)
        return item

    def placeOrder(self):
        if not self.node.order_client.wait_for_service(timeout_sec=1.0):
            print("서비스가 아직 준비되지 않았습니다.")
            self.order_button.setText("서비스 준비 중")
            self.order_button.setStyleSheet("background-color: #cc0033; color: white; font-size: 18px; font-weight: bold;")
            QTimer.singleShot(1000, self.checkServiceAvailability)
            return

        order_summary = [f'{menu_name}/{info["quantity"]}/{info["price"] * info["quantity"]}'
                         for menu_name, info in self.order_data.items()]
        table_num = self.table_label.text()
        order_time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

        request = Order.Request()
        request.table_num = table_num
        request.order_info = order_summary
        request.order_time = order_time

        future = self.node.order_client.call_async(request)
        future.add_done_callback(self.orderResponseCallback)

    def checkServiceAvailability(self):
        if self.node.order_client.wait_for_service(timeout_sec=0.1):
            self.order_button.setText("주문")
            self.order_button.setStyleSheet("background-color: #0d3383; color: white; font-size: 18px; font-weight: bold;")

    def orderResponseCallback(self, future):
        try:
            response = future.result()
            if response.is_order:
                print(f'{self.table_label.text()} {self.order_data.keys()} {datetime.now().strftime("%Y-%m-%d %H:%M:%S")}')
                print("주문 성공")
                self.showOrderSuccessPopup()
                self.cancelOrder()
        except Exception as e:
            print(f'서비스 호출 중 오류 발생: {e}')

    def showOrderSuccessPopup(self):
        msg = QMessageBox(self)
        msg.setIcon(QMessageBox.Information)
        msg.setWindowTitle("주문 성공")
        msg.setText("주문이 성공적으로 완료되었습니다!")
        msg.setStandardButtons(QMessageBox.Ok)
        msg.buttonClicked.connect(self.onPopupClose)
        msg.exec_()

    def onPopupClose(self):
        pass

    def cancelOrder(self):
        self.order_data.clear()
        self.updateOrderList()

class NODE(Node):
    def __init__(self):
        super().__init__('order_node')
        self.order_client = self.create_client(Order, 'order_service')

# 애플리케이션 실행
def main():
    rclpy.init()
    node = NODE()
    ros_thread = threading.Thread(target=lambda: rclpy.spin(node), daemon=True)
    ros_thread.start()

    app = QApplication(sys.argv)
    gui = GUI(node)
    gui.show()
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()
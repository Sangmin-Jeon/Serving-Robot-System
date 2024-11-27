import sys
import threading
import queue
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile
from rclpy.executors import MultiThreadedExecutor
from datetime import datetime

from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QLabel, QVBoxLayout, QHBoxLayout, QFrame, QTableWidget, QTableWidgetItem, QGridLayout, QGroupBox
from PyQt5.QtGui import QPixmap
from PyQt5.QtCore import Qt

from std_msgs.msg import String
from b4_serv_robot_interface.srv import Order

class GUI(QWidget):
    def __init__(self, node):
        super().__init__()
        self.node = node
        self.initUI()

    def initUI(self):
        # 창의 제목 설정
        self.setWindowTitle('주문 관리 시스템')

        # 메인 레이아웃 설정
        main_layout = QVBoxLayout()

        # 상단 레이아웃 설정 (테이블 이름과 가게 이름)
        top_layout = QHBoxLayout()
        top_layout.setContentsMargins(0, 0, 0, 20)

        # 테이블 이름 추가 (박스 안에 넣기)
        table_group_box = QGroupBox()
        table_layout = QVBoxLayout()
        self.table_label = QLabel('Table B4')
        self.table_label.setAlignment(Qt.AlignCenter)
        self.table_label.setStyleSheet("font-size: 16px; font-weight: bold;")
        table_layout.addWidget(self.table_label)
        table_group_box.setLayout(table_layout)
        table_group_box.setFixedWidth(100)
        top_layout.addWidget(table_group_box)

        # 가게 이름 추가
        shop_label = QLabel('  🐟남로먹는집🐟')
        shop_label.setStyleSheet("font-size: 24px; font-weight: bold;")
        top_layout.addWidget(shop_label)

        # 상단 레이아웃을 메인 레이아웃에 추가
        main_layout.addLayout(top_layout)

        # 메인 레이아웃 설정 (메뉴와 주문 내역)
        content_layout = QHBoxLayout()

        # 메뉴 레이아웃 (왼쪽)
        menu_layout = QVBoxLayout()
        menu_layout_widget = QWidget()
        menu_layout_widget.setLayout(menu_layout)

        # 메뉴 버튼 생성 (그리드 레이아웃)
        grid_layout = QGridLayout()
        self.menu_buttons = {
            '방엄회': {'price': 50000, 'image': 'src/b4_serv_robot/resource/Bang.jpg'},
            '향엄회': {'price': 35000, 'image': 'src/b4_serv_robot/resource/Hyang.jpg'},
            '광어+우렷 세트': {'price': 38000, 'image': 'src/b4_serv_robot/resource/GW.jpg'},
            '매운탕': {'price': 10000, 'image': 'src/b4_serv_robot/resource/Mae.jpg'},
            '소주': {'price': 5000, 'image': 'src/b4_serv_robot/resource/Han.jpeg'}
        }

        positions = [(0, 0), (0, 1), (0, 2), (1, 0), (1, 1)]
        for position, (menu_name, menu_info) in zip(positions, self.menu_buttons.items()):
            row, col = position

            # 메뉴 이미지, 이름 및 가격, +, - 버튼을 하나의 레이아웃으로 묶기
            item_layout = QVBoxLayout()

            # 메뉴 이미지 추가
            image_label = QLabel(self)
            pixmap = QPixmap(menu_info['image'])
            pixmap = pixmap.scaled(200, 200, Qt.KeepAspectRatio, Qt.SmoothTransformation)
            image_label.setPixmap(pixmap)
            image_label.setAlignment(Qt.AlignCenter)
            item_layout.addWidget(image_label)

            # 메뉴 이름 및 가격 레이블
            item_label = QLabel(f'{menu_name}\n{menu_info["price"]:,.0f}원')
            item_label.setAlignment(Qt.AlignCenter)
            item_label.setStyleSheet("font-size: 20px;")
            item_layout.addWidget(item_label)

            # +, - 버튼 레이아웃
            button_layout = QHBoxLayout()
            add_button = QPushButton('+')
            add_button.setStyleSheet("background-color: #0d3383; color: white; font-size: 18px; font-weight: bold;")
            add_button.clicked.connect(lambda checked, name=menu_name: self.addItem(name))
            button_layout.addWidget(add_button)

            remove_button = QPushButton('-')
            remove_button.setStyleSheet("background-color: #cc0033; color: white; font-size: 18px; font-weight: bold;")
            remove_button.clicked.connect(lambda checked, name=menu_name: self.removeItem(name))
            button_layout.addWidget(remove_button)

            item_layout.addLayout(button_layout)

            # 그리드 레이아웃에 아이템 레이아웃 추가
            grid_layout.addLayout(item_layout, row, col)

        menu_layout.addLayout(grid_layout)

        # 주문 내역 레이아웃 (오른쪽)
        order_layout = QVBoxLayout()
        self.order_label = QLabel('주문 내역')
        self.order_label.setStyleSheet("font-size: 18px; font-weight: bold;")
        order_layout.addWidget(self.order_label)

        # 주문 내역 테이블
        self.order_table = QTableWidget()
        self.order_table.setEditTriggers(QTableWidget.NoEditTriggers)
        self.order_table.verticalHeader().setVisible(False)
        self.order_table.setColumnCount(3)
        self.order_table.setHorizontalHeaderLabels(['메뉴명', '수량', '금액'])
        self.order_table.setColumnWidth(0, 150)
        self.order_table.setFixedWidth(400)  # 주문 내역 너비
        self.order_table.horizontalHeader().setStretchLastSection(True)
        order_layout.addWidget(self.order_table)

        # 총 금액 레이블
        self.total_label = QLabel('총 금액: 0원')
        self.total_label.setStyleSheet("font-size: 17px; font-weight: bold;")
        order_layout.addWidget(self.total_label)

        # 주문 및 취소 버튼
        button_layout = QHBoxLayout()
        self.order_button = QPushButton('주문')
        self.order_button.clicked.connect(self.placeOrder)
        button_layout.addWidget(self.order_button)

        self.cancel_button = QPushButton('취소')
        self.cancel_button.clicked.connect(self.cancelOrder)
        button_layout.addWidget(self.cancel_button)

        order_layout.addLayout(button_layout)

        # 수직 구분선
        separator = QFrame()
        separator.setFrameShape(QFrame.VLine)
        separator.setFrameShadow(QFrame.Sunken)

        # 메인 레이아웃에 추가
        content_layout.addWidget(menu_layout_widget, stretch=3)
        content_layout.addWidget(separator)
        content_layout.addLayout(order_layout, stretch=1)

        main_layout.addLayout(content_layout)

        # 레이아웃을 윈도우에 설정
        self.setLayout(main_layout)

        # 창 크기 조절
        self.resize(1000, 700)

        # 주문 내역 데이터
        self.order_data = {}

    def addItem(self, menu_name):
        # 메뉴 추가 또는 수량 증가
        if menu_name in self.order_data:
            self.order_data[menu_name]['quantity'] += 1
        else:
            self.order_data[menu_name] = {'quantity': 1, 'price': self.menu_buttons[menu_name]['price']}
        self.updateOrderList()

    def removeItem(self, menu_name):
        # 메뉴 수량 감소 또는 삭제
        if menu_name in self.order_data:
            if self.order_data[menu_name]['quantity'] > 1:
                self.order_data[menu_name]['quantity'] -= 1
            else:
                del self.order_data[menu_name]
        self.updateOrderList()

    def updateOrderList(self):
        # 주문 내역 테이블 업데이트
        self.order_table.setRowCount(0)
        total_price = 0
        for menu_name, info in self.order_data.items():
            quantity = info['quantity']
            price = info['price'] * quantity
            total_price += price

            row_position = self.order_table.rowCount()
            self.order_table.insertRow(row_position)
            item = QTableWidgetItem(menu_name)
            item.setTextAlignment(Qt.AlignVCenter | Qt.AlignLeft)
            font = item.font()
            font.setBold(True)
            item.setFont(font)
            self.order_table.setItem(row_position, 0, item)
            item = QTableWidgetItem(str(quantity))
            item.setTextAlignment(Qt.AlignCenter)
            font = item.font()
            font.setBold(True)
            item.setFont(font)
            self.order_table.setItem(row_position, 1, item)
            item = QTableWidgetItem(f'{price:,.0f}원')
            item.setTextAlignment(Qt.AlignCenter)
            font = item.font()
            font.setBold(True)
            item.setFont(font)
            self.order_table.setItem(row_position, 2, item)

        self.total_label.setText(f'총 금액: {total_price:,.0f}원')

    def placeOrder(self):
        # 주문 서비스 호출
        if not self.node.order_client.wait_for_service(timeout_sec=1.0):
            print("서비스가 아직 준비되지 않았습니다.")
            return

        order_summary = []
        for menu_name, info in self.order_data.items():
            order_summary.append(f'{menu_name}/{info["quantity"]}/{info["price"] * info["quantity"]}')

        table_num = self.table_label.text()
        order_time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")  # 현재 시간 설정

        # 서비스 요청 생성
        request = Order.Request()
        request.table_num = table_num
        request.order_info = order_summary
        request.order_time = order_time

        future = self.node.order_client.call_async(request)
        future.add_done_callback(self.orderResponseCallback)

    def orderResponseCallback(self, future):
        try:
            response = future.result()
            if response.is_order:
                print("주문 성공")
            else:
                print("주문 실패")
        except Exception as e:
            print(f'서비스 호출 중 오류 발생: {e}')

    def cancelOrder(self):
        # 주문 내역 초기화
        self.order_data.clear()
        self.updateOrderList()

class NODE(Node):
    def __init__(self):
        super().__init__('order_node')
        self.order_client = self.create_client(Order, 'place_order')

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
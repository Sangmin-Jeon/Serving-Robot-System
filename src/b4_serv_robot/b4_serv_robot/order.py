import sys
import threading
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSDurabilityPolicy, QoSHistoryPolicy, QoSProfile, QoSReliabilityPolicy
from datetime import datetime

from PyQt5.QtWidgets import (QApplication, QWidget, QPushButton, QLabel, QVBoxLayout,
                             QHBoxLayout, QFrame, QTableWidget, QTableWidgetItem, QGridLayout, QGroupBox, QMessageBox)
from PyQt5.QtGui import QPixmap
from PyQt5.QtCore import Qt, Q_ARG, QTimer, pyqtSignal

from b4_serv_robot_interface.srv import Order
from b4_serv_robot_interface.srv import OrderCancel


# GUI 클래스 정의 (PyQt5 사용)
class GUI(QWidget):
    popup_closed = pyqtSignal()  # 팝업 종료 신호 생성

    def __init__(self, node):
        super().__init__()
        self.node = node  # ROS2 노드 연결
        self.order_data = {}  # 주문 데이터를 저장할 딕셔너리
        self.initUI()  # GUI 초기화

    # GUI 초기 설정
    def initUI(self):
        self.setWindowTitle('주문 관리 시스템')  # 윈도우 제목 설정
        main_layout = QVBoxLayout()  # 메인 레이아웃 생성
        main_layout.addLayout(self.createTopLayout())  # 상단 레이아웃 추가
        main_layout.addLayout(self.AllLayout())  # 내용 레이아웃 추가
        self.setLayout(main_layout)  # 메인 레이아웃 설정
        self.resize(1000, 700)  # 윈도우 크기 조정

    # 상단 레이아웃 생성
    def createTopLayout(self):
        top_layout = QHBoxLayout()
        top_layout.setContentsMargins(0, 0, 0, 20)  # 여백 설정

        # 테이블 그룹 박스 생성
        table_group_box = QGroupBox()
        table_layout = QVBoxLayout()
        self.table_label = QLabel('B4', alignment=Qt.AlignCenter)  # 테이블 번호 라벨
        self.table_label.setStyleSheet("font-size: 16px; font-weight: bold;")
        table_layout.addWidget(self.table_label)
        table_group_box.setLayout(table_layout)
        table_group_box.setFixedWidth(100)
        top_layout.addWidget(table_group_box)

        # 가게 이름 라벨 생성
        shop_label = QLabel('  🐟날로먹는집🐟')
        shop_label.setStyleSheet("font-size: 26px; font-weight: bold;")
        top_layout.addWidget(shop_label)

        return top_layout

    # 내용 레이아웃 생성
    def AllLayout(self):
        content_layout = QHBoxLayout()
        content_layout.addWidget(self.MenuWidget(), stretch=3)  # 메뉴 위젯 추가
        content_layout.addWidget(self.Seperator())  # 구분선 추가
        content_layout.addLayout(self.OrderLayout(), stretch=1)  # 주문 레이아웃 추가
        return content_layout

    # 메뉴 위젯 생성
    def MenuWidget(self):
        menu_layout = QVBoxLayout()
        grid_layout = QGridLayout()
        # 메뉴 버튼 딕셔너리 설정
        self.menu_buttons = {
            '방어회': {'price': 50000, 'image': 'src/b4_serv_robot/resource/Bang.jpg'},
            '향어회': {'price': 35000, 'image': 'src/b4_serv_robot/resource/Hyang.jpg'},
            '광어+우럭 세트': {'price': 38000, 'image': 'src/b4_serv_robot/resource/GW.jpg'},
            '매운탕': {'price': 10000, 'image': 'src/b4_serv_robot/resource/Mae.jpg'},
            '소주': {'price': 5000, 'image': 'src/b4_serv_robot/resource/Han.jpeg'}
        }

        positions = [(0, 0), (0, 1), (0, 2), (1, 0), (1, 1)]  # 메뉴 버튼 위치 설정
        for position, (menu_name, menu_info) in zip(positions, self.menu_buttons.items()):
            grid_layout.addLayout(self.ItemLayout(menu_name, menu_info), *position)

        menu_layout.addLayout(grid_layout)
        menu_layout_widget = QWidget()
        menu_layout_widget.setLayout(menu_layout)
        return menu_layout_widget

    # 개별 메뉴 항목 레이아웃 생성
    def ItemLayout(self, menu_name, menu_info):
        item_layout = QVBoxLayout()

        # 메뉴 이미지 라벨 설정
        image_label = QLabel(self)
        pixmap = QPixmap(menu_info['image']).scaled(200, 200, Qt.KeepAspectRatio, Qt.SmoothTransformation)
        image_label.setPixmap(pixmap)
        image_label.setAlignment(Qt.AlignCenter)
        item_layout.addWidget(image_label)

        # 메뉴 이름 및 가격 라벨 설정
        item_label = QLabel(f'{menu_name}\n{menu_info["price"]:,.0f}원', alignment=Qt.AlignCenter)
        item_label.setStyleSheet("font-size: 20px;")
        item_layout.addWidget(item_label)

        # 수량 조절 버튼 생성 (+, -)
        button_layout = QHBoxLayout()
        add_button = QPushButton('+', clicked=lambda _, name=menu_name: self.addItem(name))
        add_button.setStyleSheet("background-color: #0d3383; color: white; font-size: 18px; font-weight: bold;")
        button_layout.addWidget(add_button)

        remove_button = QPushButton('-', clicked=lambda _, name=menu_name: self.removeItem(name))
        remove_button.setStyleSheet("background-color: #cc0033; color: white; font-size: 18px; font-weight: bold;")
        button_layout.addWidget(remove_button)

        item_layout.addLayout(button_layout)
        return item_layout

    # 구분선 생성
    def Seperator(self):
        separator = QFrame()
        separator.setFrameShape(QFrame.VLine)
        separator.setFrameShadow(QFrame.Sunken)
        return separator

    # 주문 레이아웃 생성
    def OrderLayout(self):
        order_layout = QVBoxLayout()

        # 주문 내역 라벨 생성
        self.order_label = QLabel('주문 내역')
        self.order_label.setStyleSheet("font-size: 18px; font-weight: bold;")
        order_layout.addWidget(self.order_label)

        # 주문 테이블 위젯 생성
        self.order_table = QTableWidget()
        self.order_table.setEditTriggers(QTableWidget.NoEditTriggers)
        self.order_table.verticalHeader().setVisible(False)
        self.order_table.setColumnCount(3)
        self.order_table.setHorizontalHeaderLabels(['메뉴명', '수량', '금액'])
        self.order_table.setColumnWidth(0, 150)
        self.order_table.setFixedWidth(400)
        self.order_table.horizontalHeader().setStretchLastSection(True)
        order_layout.addWidget(self.order_table)

        # 총 금액 라벨 생성
        self.total_label = QLabel('총 금액: 0원')
        self.total_label.setStyleSheet("font-size: 17px; font-weight: bold;")
        order_layout.addWidget(self.total_label)

        # 주문 및 취소 버튼 생성
        button_layout = QHBoxLayout()
        self.order_button = QPushButton('주문', clicked=self.placeOrder)
        button_layout.addWidget(self.order_button)
        self.cancel_button = QPushButton('취소', clicked=self.cancelOrder)
        button_layout.addWidget(self.cancel_button)

        order_layout.addLayout(button_layout)
        return order_layout

    # 메뉴 추가 기능
    def addItem(self, menu_name):
        if menu_name in self.order_data:
            self.order_data[menu_name]['quantity'] += 1
        else:
            self.order_data[menu_name] = {'quantity': 1, 'price': self.menu_buttons[menu_name]['price']}
        self.updateOrderList()

    # 메뉴 삭제 기능
    def removeItem(self, menu_name):
        if menu_name in self.order_data:
            if self.order_data[menu_name]['quantity'] > 1:
                self.order_data[menu_name]['quantity'] -= 1
            else:
                del self.order_data[menu_name]
        self.updateOrderList()

    # 주문 목록 업데이트
    def updateOrderList(self):
        self.order_table.setRowCount(0)
        total_price = 0
        for menu_name, info in self.order_data.items():
            quantity = info['quantity']
            price = info['price'] * quantity
            total_price += price

            row_position = self.order_table.rowCount()
            self.order_table.insertRow(row_position)
            self.order_table.setItem(row_position, 0, self.TableOrder(menu_name))
            self.order_table.setItem(row_position, 1, self.TableOrder(str(quantity)))
            self.order_table.setItem(row_position, 2, self.TableOrder(f'{price:,.0f}원'))

        self.total_label.setText(f'총 금액: {total_price:,.0f}원')

    # 테이블 아이템 생성 (센터 정렬, 굵게)
    def TableOrder(self, text):
        item = QTableWidgetItem(text)
        item.setTextAlignment(Qt.AlignCenter)
        font = item.font()
        font.setBold(True)
        item.setFont(font)
        return item

    # 주문하기 기능
    def placeOrder(self):
        if not self.node.order_client.wait_for_service(timeout_sec=1.0):
            self.node.get_logger().warn("서비스 준비중...")
            self.SrvXpopup()
            QTimer.singleShot(1000, self.SrvAvailabilty)
            return

        # 주문 내역 요약 생성
        order_summary = [f'{menu_name}/{info["quantity"]}/{info["price"] * info["quantity"]}'
                         for menu_name, info in self.order_data.items()]
        table_num = self.table_label.text()
        order_time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

        # 서비스 요청 생성
        request = Order.Request()
        request.table_num = table_num
        request.order_info = order_summary
        request.order_time = order_time

        # 비동기 서비스 호출
        future = self.node.order_client.call_async(request)
        future.add_done_callback(self.orderCallback)

    # 서비스 준비 상태 확인
    def SrvAvailabilty(self):
        QTimer.singleShot(1000, self.SrvAvailabilty)

    # 서비스 사용 불가 알림 팝업 표시
    def SrvXpopup(self):
        msg = QMessageBox(self)
        msg.setIcon(QMessageBox.Warning)
        msg.setWindowTitle("서비스 준비 중")
        msg.setText("서비스가 아직 준비되지 않았습니다. 잠시 후 다시 시도해주세요.")
        msg.setStandardButtons(QMessageBox.Ok)
        msg.exec_()

    # 주문 응답 콜백
    def orderCallback(self, future):
        try:
            response = future.result()
            if response.is_order:
                self.node.get_logger().info(
                    f'{self.table_label.text()} {self.order_data.keys()} {datetime.now().strftime("%Y-%m-%d %H:%M:%S")}')
                self.node.get_logger().info("주문 성공")
                # GUI 업데이트를 메인 스레드에서 실행하도록 요청
                QTimer.singleShot(0, self.OrderOKpopup)
                QTimer.singleShot(0, self.cancelOrder)
        except Exception as e:
            self.node.get_logger().error(f'서비스 호출 중 오류 발생: {e}')

    # 주문 성공 알림 팝업 표시
    def OrderOKpopup(self):
        msg = QMessageBox(self)
        msg.setIcon(QMessageBox.Information)
        msg.setWindowTitle("주문 성공")
        msg.setText("주문이 성공적으로 완료되었습니다!")
        msg.setStandardButtons(QMessageBox.Ok)
        msg.buttonClicked.connect(lambda: self.popup_closed.emit())  # 팝업 종료 시그널 발생
        msg.exec_()

    # 주문 실패 알림 팝업 표시
    def OrderFailedPopup(self):
        msg = QMessageBox(self)
        msg.setIcon(QMessageBox.Warning)
        msg.setWindowTitle("주문 실패")
        msg.setText("주문이 취소되었습니다. 다시 시도해주세요.")
        msg.setStandardButtons(QMessageBox.Ok)
        msg.buttonClicked.connect(lambda: self.popup_closed.emit())  # 팝업 종료 시그널 발생
        msg.exec_()

    # 주문 취소 기능
    def cancelOrder(self):
        self.order_data.clear()
        self.updateOrderList()


# ROS2 노드 정의
class NODE(Node):
    def __init__(self, gui):
        super().__init__('order_node')
        self.gui = gui

        QoS_Order = QoSProfile(
            reliability=QoSReliabilityPolicy.RELIABLE,  # 주문, 취소 정보를 잃어버리지 않도록 신뢰성 보장
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=1,  # 최신 주문, 취소 정보만 유지
            durability=QoSDurabilityPolicy.VOLATILE  # 노드가 종료되면 정보 유지 필요 없음
        )

        self.order_client = self.create_client(Order, 'order_service', qos_profile=QoS_Order)  # 주문 서비스 클라이언트 생성
        self.cancel_server = self.create_service(OrderCancel, 'order_cancel_service', self.cancelOrderCallback,
                                                 qos_profile=QoS_Order)  # 취소 서비스 클라이언트 추가

    # 주문 취소 콜백 추가
    def cancelOrderCallback(self, request, response):
        response.cancel_confirm = True
        self.get_logger().info("주문이 취소되었습니다.")
        QTimer.singleShot(0, self.gui.OrderFailedPopup)  # 주문 취소 팝업 호출
        return response


# 애플리케이션 실행 함수
def main():
    rclpy.init()  # ROS2 초기화
    app = QApplication(sys.argv)  # PyQt5 애플리케이션 생성
    gui = GUI(None)  # GUI 인스턴스 생성 (초기에는 node가 없음)
    node = NODE(gui)  # ROS2 노드 생성 및 GUI 연결
    gui.node = node  # GUI에 노드 연결
    ros_thread = threading.Thread(target=lambda: rclpy.spin(node), daemon=True)  # ROS2 스레드 시작
    ros_thread.start()

    gui.show()  # GUI 표시

    try:
        exit_code = app.exec_()  # 애플리케이션 실행
    except KeyboardInterrupt:
        node.get_logger().info("Keyboard Interrupt Close")
    finally:
        node.destroy_node()
        rclpy.shutdown()  # 애플리케이션 종료 후 ROS2 종료
        sys.exit(exit_code)


if __name__ == '__main__':
    main()
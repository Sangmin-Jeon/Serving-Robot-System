import sys
import sqlite3
import threading
import rclpy
from rclpy.node import Node
from b4_serv_robot_interface.msg import DB
from rclpy.qos import QoSProfile
from PyQt5.QtWidgets import QApplication, QMainWindow, QVBoxLayout, QHBoxLayout, QWidget, QCheckBox, QTableWidget, \
    QTableWidgetItem, QLabel, QDateEdit, QLineEdit, QSizePolicy, QSplitter
from PyQt5.QtCore import Qt, QDate, QTimer
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
import matplotlib.pyplot as plt
import numpy as np

# Set Korean font for the graph
plt.rcParams['font.family'] = 'NanumGothic'
plt.rcParams['axes.unicode_minus'] = False


class StatisticsApp(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("대시보드")
        self.setGeometry(100, 100, 1600, 900)

        # 데이터베이스 연결 설정
        self.conn = sqlite3.connect('order_management11.db')
        self.cursor = self.conn.cursor()

        # 고정지출 설정
        self.fixed_expense = 30000  # 예시 값

        # 메인 위젯과 레이아웃 설정
        self.main_widget = QWidget()
        self.setCentralWidget(self.main_widget)
        self.main_layout = QVBoxLayout(self.main_widget)
        self.main_layout.setContentsMargins(10, 10, 10, 10)
        self.main_layout.setSpacing(5)

        # 상단 레이아웃 (히스토그램 및 테이블) - QSplitter 사용
        self.upper_splitter = QSplitter(Qt.Vertical)
        self.main_layout.addWidget(self.upper_splitter)

        # 메뉴 필터링 체크박스
        self.menu_checkboxes_layout = QHBoxLayout()
        self.menu_checkboxes_layout.setSpacing(5)
        self.menu_checkboxes = []
        self.menu_labels = ["방어회", "향어회", "광어+우럭 세트", "매운탕", "소주"]
        for label in self.menu_labels:
            checkbox = QCheckBox(label)
            checkbox.setChecked(True)
            checkbox.stateChanged.connect(self.update_graph_and_table)
            self.menu_checkboxes.append(checkbox)
            self.menu_checkboxes_layout.addWidget(checkbox)

        # 고정지출 입력
        self.fixed_expense_label = QLabel("고정지출:")
        self.fixed_expense_input = QLineEdit(str(self.fixed_expense))
        self.fixed_expense_input.setFixedWidth(50)
        self.fixed_expense_input.editingFinished.connect(self.update_fixed_expense)
        self.menu_checkboxes_layout.addWidget(self.fixed_expense_label)
        self.menu_checkboxes_layout.addWidget(self.fixed_expense_input)

        # 날짜 선택 위젯
        self.date_selection_layout = QVBoxLayout()
        self.date_selection_layout.setSpacing(5)
        self.start_date_label = QLabel("시작 날짜:")
        self.start_date_edit = QDateEdit()
        self.start_date_edit.setCalendarPopup(True)
        self.start_date_edit.setDate(QDate.currentDate().addDays(-10))
        self.start_date_edit.dateChanged.connect(self.update_graph_and_table)

        self.end_date_label = QLabel("종료 날짜:")
        self.end_date_edit = QDateEdit()
        self.end_date_edit.setCalendarPopup(True)
        self.end_date_edit.setDate(QDate.currentDate())
        self.end_date_edit.dateChanged.connect(self.update_graph_and_table)

        self.date_selection_layout.addWidget(self.start_date_label)
        self.date_selection_layout.addWidget(self.start_date_edit)
        self.date_selection_layout.addWidget(self.end_date_label)
        self.date_selection_layout.addWidget(self.end_date_edit)

        self.menu_checkboxes_layout.addLayout(self.date_selection_layout)
        self.menu_checkboxes_layout.addStretch(1)

        # 메뉴 필터링 체크박스를 상단 레이아웃에 추가
        upper_widget = QWidget()
        upper_widget.setLayout(self.menu_checkboxes_layout)
        self.upper_splitter.addWidget(upper_widget)

        # 히스토그램 (메뉴별 매출 시각화)
        self.figure, self.ax = plt.subplots(figsize=(10, 4))
        self.canvas = FigureCanvas(self.figure)
        self.upper_splitter.addWidget(self.canvas)
        self.update_graph()

        # 테이블 설정
        self.table = QTableWidget()
        self.table.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Minimum)
        self.upper_splitter.addWidget(self.table)
        self.update_table_data()

        # 상단 레이아웃 조정 - 히스토그램과 테이블 비율 조정
        self.upper_splitter.setStretchFactor(1, 1)
        self.upper_splitter.setStretchFactor(2, 1)

        # 하단 레이아웃 (도넛 차트 및 추가 그래프)
        self.lower_layout = QHBoxLayout()

        # 도넛 차트 설정
        self.donut_layout = QVBoxLayout()
        self.device_figure, self.device_ax = plt.subplots()
        self.device_canvas = FigureCanvas(self.device_figure)
        self.device_canvas.setSizePolicy(QSizePolicy.Fixed, QSizePolicy.Fixed)
        self.device_canvas.setMinimumSize(300, 300)
        self.donut_layout.addWidget(self.device_canvas)
        self.lower_layout.addLayout(self.donut_layout)

        # 일별 매출 그래프 설정
        self.daily_sales_figure, self.daily_sales_ax = plt.subplots()
        self.daily_sales_canvas = FigureCanvas(self.daily_sales_figure)
        self.daily_sales_canvas.setSizePolicy(QSizePolicy.Fixed, QSizePolicy.Fixed)
        self.daily_sales_canvas.setMinimumSize(400, 300)
        self.lower_layout.addWidget(self.daily_sales_canvas)

        # 시간별 매출 그래프 설정
        self.hourly_sales_figure, self.hourly_sales_ax = plt.subplots()
        self.hourly_sales_canvas = FigureCanvas(self.hourly_sales_figure)
        self.hourly_sales_canvas.setSizePolicy(QSizePolicy.Fixed, QSizePolicy.Fixed)
        self.hourly_sales_canvas.setMinimumSize(400, 300)
        self.lower_layout.addWidget(self.hourly_sales_canvas)

        # 하단 레이아웃을 메인 레이아웃에 추가
        self.main_layout.addLayout(self.lower_layout)

        # 초기 그래프 업데이트
        self.update_device_chart()
        self.update_daily_sales_chart()
        self.update_hourly_sales_chart()

        # 데이터 업데이트 타이머 설정 (데이터 수신 시 화면 업데이트)
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.update_graph_and_table)
        self.timer.start(1000)  # 1초마다 업데이트

    def update_fixed_expense(self):
        try:
            self.fixed_expense = int(self.fixed_expense_input.text())
            self.update_graph_and_table()
        except ValueError:
            self.fixed_expense_input.setText(str(self.fixed_expense))

    def update_graph_and_table(self):
        self.update_graph()
        self.update_table_data()
        self.update_device_chart()
        self.update_daily_sales_chart()
        self.update_hourly_sales_chart()

    def get_filtered_data(self):
        start_date = self.start_date_edit.date().toString("yyyy-MM-dd")
        end_date = self.end_date_edit.date().toString("yyyy-MM-dd")

        query = '''
        SELECT DATE(o.order_time) as order_date,
            SUM(COALESCE(bang_eo.menu_count * bang_eo.menu_price, 0)) AS 방어회_sales,
            SUM(COALESCE(hyang_eo.menu_count * hyang_eo.menu_price, 0)) AS 향어회_sales,
            SUM(COALESCE(gwang_eo.menu_count * gwang_eo.menu_price, 0)) AS 광어우럭세트_sales,
            SUM(COALESCE(maeun_tang.menu_count * maeun_tang.menu_price, 0)) AS 매운탕_sales,
            SUM(COALESCE(soju.menu_count * soju.menu_price, 0)) AS 소주_sales
        FROM OrderTable o
        LEFT JOIN 방어회 bang_eo ON o.order_id = bang_eo.order_id
        LEFT JOIN 향어회 hyang_eo ON o.order_id = hyang_eo.order_id
        LEFT JOIN 광어우럭세트 gwang_eo ON o.order_id = gwang_eo.order_id
        LEFT JOIN 매운탕 maeun_tang ON o.order_id = maeun_tang.order_id
        LEFT JOIN 소주 soju ON o.order_id = soju.order_id
        WHERE o.order_time BETWEEN ? AND ? AND o.cancel_status = 0
        GROUP BY order_date
        ORDER BY order_date
    '''
        self.cursor.execute(query, (start_date, end_date))
        data = self.cursor.fetchall()

        dates = [start_date]
        current_date = QDate.fromString(start_date, "yyyy-MM-dd")
        end_date = QDate.fromString(end_date, "yyyy-MM-dd")

        while current_date < end_date:
            current_date = current_date.addDays(1)
            dates.append(current_date.toString("yyyy-MM-dd"))

        complete_data = []
        data_dict = {row[0]: row[1:] for row in data}
        for date in dates:
            if date in data_dict:
                complete_data.append((date,) + data_dict[date])
            else:
                complete_data.append((date, 0, 0, 0, 0, 0))

        return complete_data

    def get_filtered_hourly_data(self):
        start_date = self.start_date_edit.date().toString("yyyy-MM-dd")
        end_date = self.end_date_edit.date().toString("yyyy-MM-dd")

        query = '''
            SELECT STRFTIME('%H', o.order_time) as hour,
                   SUM(COALESCE(bang_eo.menu_count * bang_eo.menu_price, 0) + COALESCE(hyang_eo.menu_count * hyang_eo.menu_price, 0) + COALESCE(gwang_eo.menu_count * gwang_eo.menu_price, 0) +
                       COALESCE(maeun_tang.menu_count * maeun_tang.menu_price, 0) + COALESCE(soju.menu_count * soju.menu_price, 0)) AS total_sales
            FROM OrderTable o
            LEFT JOIN 방어회 bang_eo ON o.order_id = bang_eo.order_id
            LEFT JOIN 향어회 hyang_eo ON o.order_id = hyang_eo.order_id
            LEFT JOIN 광어우럭세트 gwang_eo ON o.order_id = gwang_eo.order_id
            LEFT JOIN 매운탕 maeun_tang ON o.order_id = maeun_tang.order_id
            LEFT JOIN 소주 soju ON o.order_id = soju.order_id
            WHERE o.order_time BETWEEN ? AND ? AND o.cancel_status = 0
            GROUP BY hour
            ORDER BY hour
        '''

        self.cursor.execute(query, (start_date, end_date))
        data = self.cursor.fetchall()

        hourly_sales = {str(hour).zfill(2): 0 for hour in range(9, 25)}
        for row in data:
            hour, sales = row
            hourly_sales[hour] = sales

        return hourly_sales

    def update_graph(self):
        data = self.get_filtered_data()
        if len(data) > 30:
            self.ax.clear()
            self.ax.text(0.5, 0.5, "일별 데이터가 30일을 초과했습니다. 30일 이하의 기간을 선택하세요.",
                         horizontalalignment='center', verticalalignment='center', transform=self.ax.transAxes,
                         fontsize=12, color='red')
            self.canvas.draw()
            return

        self.ax.clear()
        bar_width = 0.1
        indices = np.arange(len(data))

        total_sales = np.zeros(len(data))
        for idx, menu_label in enumerate(self.menu_labels):
            if self.menu_checkboxes[idx].isChecked():
                menu_sales = [row[1 + idx] for row in data]
                self.ax.bar(indices + idx * bar_width, menu_sales, bar_width, label=menu_label)
                total_sales += np.array(menu_sales)

        self.ax.bar(indices + bar_width * len(self.menu_labels), total_sales, bar_width, color='red', label='총 매출')
        self.ax.set_title("메뉴별 일일 매출")
        self.ax.set_xticks(indices + bar_width * (len(self.menu_labels) / 2))
        self.ax.set_xticklabels([row[0][5:] for row in data], rotation=45)  # 월-일만 표시하도록 수정
        self.ax.legend()
        self.canvas.draw()

    def update_table_data(self):
        data = self.get_filtered_data()
        if len(data) > 30:
            self.table.setRowCount(1)
            self.table.setColumnCount(1)
            self.table.setItem(0, 0, QTableWidgetItem("일별 데이터가 30일을 초과했습니다. 30일 이하의 기간을 선택하세요."))
            self.table.item(0, 0).setTextAlignment(Qt.AlignCenter)
            return

        self.table.setRowCount(4)
        self.table.setColumnCount(len(data) + 1)
        self.table.setHorizontalHeaderLabels([f"{row[0]}" for row in data] + ["총합계"])
        self.table.setVerticalHeaderLabels(["총 매출", "물품 원가", "고정 지출", "매출 이익"])

        total_item_cost = 0
        total_fixed_expense = 0
        total_profit = 0
        total_sales = 0

        for col_idx, row_data in enumerate(data):
            sales = sum(row_data[1:])
            item_cost = sales * 0.4
            fixed_expense = self.fixed_expense
            profit = sales - item_cost - fixed_expense

            self.table.setItem(0, col_idx, QTableWidgetItem(str(int(sales))))
            self.table.setItem(1, col_idx, QTableWidgetItem(str(int(item_cost))))
            self.table.setItem(2, col_idx, QTableWidgetItem(str(fixed_expense)))
            self.table.setItem(3, col_idx, QTableWidgetItem(str(int(profit))))

            total_sales += sales
            total_item_cost += item_cost
            total_fixed_expense += fixed_expense
            total_profit += profit

        self.table.setItem(0, len(data), QTableWidgetItem(str(int(total_sales))))
        self.table.setItem(1, len(data), QTableWidgetItem(str(int(total_item_cost))))
        self.table.setItem(2, len(data), QTableWidgetItem(str(total_fixed_expense)))
        self.table.setItem(3, len(data), QTableWidgetItem(str(int(total_profit))))

        for row in range(4):
            for col in range(len(data) + 1):
                self.table.item(row, col).setTextAlignment(Qt.AlignCenter)

    def update_device_chart(self):
        if len(self.get_filtered_data()) > 30:
            self.device_ax.clear()
            self.device_ax.text(0.5, 0.5, "일별 데이터가 30일을 초과했습니다. 30일 이하의 기간을 선택하세요.",
                                horizontalalignment='center', verticalalignment='center',
                                transform=self.device_ax.transAxes, fontsize=12, color='red')
            self.device_canvas.draw()
            return

        self.device_ax.clear()
        try:
            total_item_cost = sum([int(self.table.item(1, i).text()) for i in range(self.table.columnCount() - 1)])
            total_fixed_expense = sum([int(self.table.item(2, i).text()) for i in range(self.table.columnCount() - 1)])
            total_profit = sum([int(self.table.item(3, i).text()) for i in range(self.table.columnCount() - 1)])

            if total_item_cost <= 0 and total_fixed_expense <= 0 and total_profit <= 0:
                donut_data = [1, 1, 1]
                donut_labels = ["물품 원가 (없음)", "고정 지출 (없음)", "매출 이익 (없음)"]
            else:
                donut_data = [
                    max(total_item_cost, 0),
                    max(total_fixed_expense, 0),
                    max(total_profit, 0)
                ]
                donut_labels = ["물품 원가", "고정 지출", "매출 이익"]

        except (AttributeError, ValueError):
            donut_data = [1, 1, 1]
            donut_labels = ["물품 원가 (없음)", "고정 지출 (없음)", "매출 이익 (없음)"]

        colors = ['#76c7c0', '#4b7bec', '#ff9999']
        self.device_ax.pie(donut_data, labels=donut_labels, autopct='%1.1f%%', startangle=140, colors=colors,
                           wedgeprops={'width': 0.3})
        self.device_ax.set_title("매출 구성 도넛 차트 (%)")
        self.device_canvas.draw()

    def update_daily_sales_chart(self):
        data = self.get_filtered_data()
        if len(data) > 30:
            self.daily_sales_ax.clear()
            self.daily_sales_ax.text(0.5, 0.5, "일별 데이터가 30일을 초과했습니다. 30일 이하의 기간을 선택하세요.",
                                     horizontalalignment='center', verticalalignment='center',
                                     transform=self.daily_sales_ax.transAxes, fontsize=12, color='red')
            self.daily_sales_canvas.draw()
            return

        self.daily_sales_ax.clear()
        dates = [row[0][5:] for row in data]  # 월-일만 표시하도록 수정
        total_sales = [sum(row[1:]) for row in data]

        self.daily_sales_ax.plot(dates, total_sales, marker='o')
        self.daily_sales_ax.set_title("일별 매출액")
        self.daily_sales_ax.set_xlabel("날짜")
        self.daily_sales_ax.set_ylabel("매출액")
        self.daily_sales_ax.grid(True)
        self.daily_sales_canvas.draw()

    def update_hourly_sales_chart(self):
        hourly_data = self.get_filtered_hourly_data()
        if len(self.get_filtered_data()) > 30:
            self.hourly_sales_ax.clear()
            self.hourly_sales_ax.text(0.5, 0.5, "일별 데이터가 30일을 초과했습니다. 30일 이하의 기간을 선택하세요.",
                                      horizontalalignment='center', verticalalignment='center',
                                      transform=self.hourly_sales_ax.transAxes, fontsize=12, color='red')
            self.hourly_sales_canvas.draw()
            return

        self.hourly_sales_ax.clear()
        hours = list(hourly_data.keys())
        sales_amount = list(hourly_data.values())

        self.hourly_sales_ax.plot(hours, sales_amount, marker='o')
        self.hourly_sales_ax.set_title("시간별 매출액 (30분 단위 합산)")
        self.hourly_sales_ax.set_xlabel("시간")
        self.hourly_sales_ax.set_ylabel("매출액")
        self.hourly_sales_ax.grid(True)
        self.hourly_sales_canvas.draw()


class DatabaseNode(Node):
    def __init__(self):
        super().__init__('database_node')
        qos_profile = QoSProfile(depth=5)  # QoS 프로필 정의
        self.subscription = self.create_subscription(
            DB,
            'order_db_message',
            self.order_callback,
            qos_profile
        )
        # SQLite 데이터베이스 연결 및 테이블 생성
        self.conn = sqlite3.connect('order_management11.db')
        self.cursor = self.conn.cursor()
        self.create_tables()
        self.seen_data = set()  # 중복 데이터 확인용

    def create_tables(self):
        # 중심 테이블: OrderTable 생성
        self.cursor.execute('''
        CREATE TABLE IF NOT EXISTS OrderTable (
            order_id INTEGER PRIMARY KEY AUTOINCREMENT,
            order_time TEXT NOT NULL,
            table_number TEXT NOT NULL,
            cancel_status BOOLEAN NOT NULL,
            completion_time TEXT
        )
        ''')
        # 메뉴별 테이블 생성 (방어회, 향어회 등)
        menu_list = ['방어회', '향어회', '광어우럭세트', '매운탕', '소주']
        for menu_name in menu_list:
            self.cursor.execute(f'''
            CREATE TABLE IF NOT EXISTS {menu_name} (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                order_id INTEGER NOT NULL,
                menu_price REAL NOT NULL,
                menu_count INTEGER NOT NULL,
                FOREIGN KEY (order_id) REFERENCES OrderTable(order_id)
            )
            ''')
        self.conn.commit()

    def insert_order(self, order_time, table_number, cancel_status, completion_time):
        self.cursor.execute('''
        INSERT INTO OrderTable (order_time, table_number, cancel_status, completion_time)
        VALUES (?, ?, ?, ?)
        ''', (order_time, table_number, cancel_status, completion_time))
        self.conn.commit()
        return self.cursor.lastrowid  # 삽입된 order_id 반환

    def insert_menu(self, menu_table, order_id, menu_price, menu_count):
        self.cursor.execute(f'''
        INSERT INTO {menu_table} (order_id, menu_price, menu_count)
        VALUES (?, ?, ?)
        ''', (order_id, menu_price, menu_count))
        self.conn.commit()

    def insert_data(self, data_list):
        if not data_list:
            return
        try:
            # Define a dictionary to map incoming menu names to database table names
            menu_name_mapping = {
                "방어회": "방어회",
                "향어회": "향어회",
                "광어+우럭 세트": "광어우럭세트",
                "매운탕": "매운탕",
                "소주": "소주"
            }

            # 첫 번째 데이터로 주문 정보를 삽입하고 order_id를 획득
            first_values = data_list[0].split('/')
            table_number = first_values[0]  # 테이블 번호는 이전에 str 형식
            cancel_status = first_values[4].lower() == 'true'
            order_time = first_values[5]
            completion_time = first_values[6] if first_values[6].lower() != 'null' else None

            # 주문 정보 삽입
            inserted_order_id = self.insert_order(order_time, table_number, cancel_status, completion_time)

            # 나머지 데이터로 메뉴 정보를 삽입
            for data in data_list:
                if data in self.seen_data:
                    continue
                self.seen_data.add(data)
                values = data.split('/')
                menu_name = values[1]

                # Use the mapping dictionary to get the correct table name
                if menu_name in menu_name_mapping:
                    mapped_menu_name = menu_name_mapping[menu_name]
                else:
                    self.get_logger().error(f"Unknown menu name: {menu_name}")
                    continue

                menu_count = int(values[2])
                menu_price = float(values[3])

                # 메뉴 정보 삽입 (메뉴 이름을 테이블 이름으로 사용)
                self.insert_menu(mapped_menu_name, inserted_order_id, menu_price, menu_count)

        except ValueError as e:
            self.get_logger().error(f"Error parsing data: {data_list[0]} -> {e}")

    def order_callback(self, msg):
        print(msg.order_info)
        data_list = msg.order_info  # 이미 리스트 형태로 사용
        self.insert_data(data_list)

        # 데이터 수신 후 화면 업데이트
        QApplication.instance().processEvents()


def run_ros2_node():
    rclpy.init()
    node = DatabaseNode()
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


def main():
    ros_thread = threading.Thread(target=run_ros2_node)
    ros_thread.start()

    app = QApplication(sys.argv)
    window = StatisticsApp()
    window.show()
    sys.exit(app.exec_())


if __name__ == "__main__":
    main()

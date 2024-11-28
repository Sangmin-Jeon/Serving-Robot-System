import rclpy
from rclpy.node import Node
from b4_serv_robot_interface.msg import DB
import sqlite3
from rclpy.qos import QoSProfile


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
            # 첫 번째 데이터로 주문 정보를 삽입하고 order_id를 획득
            first_values = data_list[0].split('/')
            table_number = first_values[0]  # 테이블 번호는 이제 str 형식
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
                # 메뉴 이름 변경: "광어+우럭 세트" -> "광어우럭세트"
                if menu_name == "광어+우럭 세트":
                    menu_name = "광어우럭세트"
                menu_count = int(values[2])
                menu_price = float(values[3])
                # 메뉴 정보 삽입 (메뉴 이름을 테이블 이름으로 사용)
                if menu_name not in ['방어회', '향어회', '광어우럭세트', '매운탕', '소주']:
                    self.get_logger().error(f"Unknown menu name: {menu_name}")
                    continue
                self.insert_menu(menu_name, inserted_order_id, menu_price, menu_count)
        except ValueError as e:
            self.get_logger().error(f"Error parsing data: {data_list[0]} -> {e}")


    def order_callback(self, msg):
        print(msg.order_info)
        data_list = msg.order_info  # 이미 리스트 형태이므로 그대로 사용
        self.insert_data(data_list)


# ROS2 실행 함수
def main(args=None):
    rclpy.init(args=args)
    node = DatabaseNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

    
if __name__ == '__main__':
    main()
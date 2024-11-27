from PyQt5.QtWidgets import QApplication, QMainWindow, QComboBox, QVBoxLayout, QWidget, QCheckBox, QHBoxLayout, QLabel, QTabWidget, QPushButton
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
import matplotlib.pyplot as plt

from PyQt5.QtWidgets import QApplication, QMainWindow, QVBoxLayout, QWidget, QTableWidget, QTableWidgetItem
from PyQt5.QtCore import Qt

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

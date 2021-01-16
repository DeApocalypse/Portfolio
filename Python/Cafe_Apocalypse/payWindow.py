import sys
from PyQt5.QtWidgets import *
from filemanager import FileManager

class PayWindow(QDialog):
    def __init__(self,menulist):
        super().__init__()
        self.setGeometry(300,300,600,300)
        self.setWindowTitle('pay window')
        lb=QLabel('현재 주문한 메뉴:', self)
        lb.move(20,10)
        self.menulist=menulist
        #테이블위젯생성
        self.tw=QTableWidget(self)
        self.tw.resize(317,147)
        self.tw.move(50,35)
        #위젯 행,열 지정
        self.tw.setRowCount(4) #행
        self.tw.setColumnCount(3)# 열
        self.total=0
        #각 테이블에 값 넣기
        for i in range(4):
            self.tw.setItem(i,0,QTableWidgetItem(menulist[i].menuName))
            self.tw.setItem(i,1,QTableWidgetItem(str(menulist[i].price)))
            self.tw.setItem(i,2,QTableWidgetItem(str(menulist[i].num)))
            self.total+=(menulist[i].price*menulist[i].num)
        headlabel=['메뉴명','수량','가격']
        self.tw.setHorizontalHeaderLabels(headlabel)
        #라벨
        tlb=QLabel('전체 금액:',self)
        tlb.move(20,200)
        totalLb=QLabel(str(self.total)+'원',self)
        totalLb.move(100,200)

        mlb=QLabel('지불할 금액:',self)
        mlb.move(20,230)

        self.moneyLine=QLineEdit('',self)
        self.moneyLine.resize(140,25)
        self.moneyLine.move(100,225)
        #버튼
        backBtn=QPushButton('취소하기',self)
        backBtn.resize(100,30)
        backBtn.move(400,50)
        backBtn.clicked.connect(self.back_slot)

        payBtn=QPushButton('결제하기',self)
        payBtn.resize(100,30)
        payBtn.move(400,120)
        payBtn.clicked.connect(self.pay_slot)
    def back_slot(self):
        QMessageBox.about(self,'close','취소합니다')
        self.close()
    def pay_slot(self):
        money=self.moneyLine.text()
        #영수증 출력하기
        FileManager.billsWrite(self.menulist,self.total,money)
        self.close()


if __name__=='__main__':
    app = QApplication(sys.argv)
    pw=PayWindow()
    pw.exec_()
    app.exec_()

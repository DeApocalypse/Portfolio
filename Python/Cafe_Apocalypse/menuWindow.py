import sys
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import Qt
from ordermanager import OrderManager as om

class OrderWindow(QDialog):
    def __init__(self):
        super().__init__()
        self.setGeometry(300,300,650,350)
        self.setWindowTitle('MenuPane')
        #Label지정
        ameLb=QLabel(self)
        ame=QLabel('[Americano]',self)
        ame.move(50,10)
        ameLb.move(10,30)
        ameLb.resize(150,180)
        #---
        eso=QLabel('[Essopresso]',self)
        eso.move(210,10)
        esoLb=QLabel(self)
        esoLb.move(170,30)
        esoLb.resize(150,180)
        #---
        lt=QLabel('[CafeLatte]',self)
        lt.move(380,10)
        ltLb=QLabel(self)
        ltLb.move(330,30)
        ltLb.resize(150,180)
        #---
        gr=QLabel('[GreenTea]',self)
        gr.move(540,10)
        grLb=QLabel(self)
        grLb.move(490,30)
        grLb.resize(150,180)
        #americano 이미지 설정
        ameImg=QPixmap('img/ameImg.jpg')
        ameImg.scaled(100,100)
        ameLb.setPixmap(ameImg)
        ameLb.setAlignment(Qt.AlignCenter)
        #esopresso 이미지 설정
        esoImg=QPixmap('img/esoImg.jpg')
        esoImg.scaled(100,100)
        esoLb.setPixmap(esoImg)
        esoLb.setAlignment(Qt.AlignCenter)
        #latte 이미지 설정
        ltImg=QPixmap('img/ltImg.jpg')
        ltImg.scaled(100,100)
        ltLb.setPixmap(ltImg)
        ltLb.setAlignment(Qt.AlignCenter)
        #greentea 이미지 설정
        grImg=QPixmap('img/grImg.jpg')
        grImg.scaled(100,100)
        grLb.setPixmap(grImg)
        grLb.setAlignment(Qt.AlignCenter)
        #SpinBox
        self.amesp = QSpinBox(self)
        self.amesp.move(40,230)
        self.amesp.resize(100,30)
        self.esosp = QSpinBox(self)
        self.esosp.move(200,230)
        self.esosp.resize(100,30)
        self.ltsp = QSpinBox(self)
        self.ltsp.move(360,230)
        self.ltsp.resize(100,30)
        self.grsp = QSpinBox(self)
        self.grsp.move(520,230)
        self.grsp.resize(100,30)
        #버튼
        cancelBtn=QPushButton('cancel',self)
        cancelBtn.resize(100,30)
        orderBtn=QPushButton('order',self)
        orderBtn.resize(100,30)
        cancelBtn.move(350,300)
        orderBtn.move(500,300)
        #이벤트
        cancelBtn.clicked.connect(self.cancelBtn_slot)
        orderBtn.clicked.connect(self.orderBtn_slot)
    def cancelBtn_slot(self):
        QMessageBox.about(self,'cancel','취소합니다')
        self.close()
    def orderBtn_slot(self):
        numlist=[]
        ameCount=self.amesp.value()
        numlist.append(ameCount)
        esoCount=self.esosp.value()
        numlist.append(esoCount)
        ltCount=self.ltsp.value()
        numlist.append(ltCount)
        grCount=self.grsp.value()
        numlist.append(grCount)
        om.order(numlist)
        self.close()
if __name__=='__main__':
    app=QApplication(sys.argv)
    ow=OrderWindow()
    ow.exec_()
    app.exec_()

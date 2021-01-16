import sys
from PyQt5.QtWidgets import *
from menuWindow import *

class MyWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.setGeometry(300,300,300,200)
        self.setWindowTitle('Cafe Program')

        title=QLabel('Cafe Main',self)
        title.resize(100,30)
        title.move(120,30)

        orderBtn=QPushButton('주문하기',self)
        cancelBtn=QPushButton('끝내기',self)
        
        orderBtn.move(50,100)
        orderBtn.resize(100,40)
        cancelBtn.move(170,100)
        cancelBtn.resize(100,40)

        orderBtn.clicked.connect(self.orderBtn_slot)
        cancelBtn.clicked.connect(self.cancelBtn_slot)
    def orderBtn_slot(self):
        ow=OrderWindow()
        ow.exec_()
        self.close()
           
    def cancelBtn_slot(self):
        QMessageBox.about(self,'close','종료합니다')
        self.close()           
        
        

if __name__ == '__main__':
    app=QApplication(sys.argv)
    mw=MyWindow()
    mw.show()
    app.exec_()
        

#ordermanager.py
#주문메뉴들의 정보를 관리하는 클래스
from order import Order
from payWindow import PayWindow
class OrderManager:
    def orderInit():
        OrderManager.menulist=[]
        for i in range(4):
            OrderManager.menulist.append(Order())
        OrderManager.menulist[0].menuName='Americano'
        OrderManager.menulist[0].price=3800
        OrderManager.menulist[1].menuName='Esopresso'
        OrderManager.menulist[1].price=2200
        OrderManager.menulist[2].menuName='CafeLatte'
        OrderManager.menulist[2].price=4500
        OrderManager.menulist[3].menuName='Greentea'
        OrderManager.menulist[3].price=5200

        for i in range(4):
            OrderManager.menulist[i].num=0
    def order(numlist):
        #menulist 값 초기화
        OrderManager.orderInit()
        #menulist의 수량을 spinbox의 수량으로 변경
        for i in range(4):
            OrderManager.menulist[i].num=numlist[i]
        for i in range(4):
            OrderManager.menulist[i].print()
        pm =PayWindow(OrderManager.menulist)
        pm.exec_()
        




        
        

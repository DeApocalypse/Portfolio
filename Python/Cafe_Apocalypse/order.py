#order.py
#주문에 관한 정보를 저장할 틀
class Order:
    menuName=''
    price=0
    num=0 #수량
    def print(self):
        print('menuName:',self.menuName)
        print('price:',self.price,'원')
        print('num:',self.num,'개')

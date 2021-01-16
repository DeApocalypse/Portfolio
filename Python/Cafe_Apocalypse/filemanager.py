#filemanager

class FileManager:
    def billsWirte():
        f=open('bills.txt','w')
        f.write('----------주문내역-----------\n')
        for i in range(4):
            f.write(menulist[i].menuName)
            f.write('\t')
            f.write(menulist[i].num)
            f.write('\n')
        f.write('--------------------------\n')
        f.write('총 금액:\t')
        f.write(str(total)+'원\n')
        f.write('지불한 금액:\t')
        f.write('잔돈:\t')
        f.write(str(money-total)+'원\n')
        f.close()

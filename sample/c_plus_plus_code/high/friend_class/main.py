# 在python中定义私有变量只需要在变量名或函数名前加上 ”__“两个下划线，那么这个函数或变量就是私有的了

class A(object):
    def __init__(self):
        # 定义私有变量
        # "双下划线 " 开始的是私有成员，意思是 只有类对象自己能访问，连子类对象也不能访问到这个数据
        self.__data = []
        # _xxx " 单下划线 " 开始的成员变量叫做保护变量，意思是只有类实例和子类实例能访问到这些变量
        self._test = "abc"
    
    def add(self, item):
        self.__data.append(item)
    
    def __pop(self):
        self.__data.pop()
    
    def printData(self):
        print(self.__data)
        # self.__pop
    
    



if __name__ == "__main__":
    a = A()
    a.add(1)
    a.add(2)
    a.printData()
    print(a._A__data)
    a._A__pop()
    a.printData()
    print(a._test)
    # print(dir(a))





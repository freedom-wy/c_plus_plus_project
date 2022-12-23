from abc import ABCMeta, abstractmethod

class Person(metaclass=ABCMeta):
    @abstractmethod
    def run(self):
        pass


class zhangSan(Person):
    # 继承抽象类必须要实现抽象类中的方法
    def run(self):
        print("张三的run方法")


if __name__ == "__main__":
    z = zhangSan()
    z.run()
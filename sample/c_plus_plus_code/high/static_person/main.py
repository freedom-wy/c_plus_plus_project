class Person(object):
    
    p_A = 100

    def __init__(self) -> None:
        self.p_B = 200
        # self.p_A = 400
    
    @classmethod
    def test01(cls):
        cls.p_A = 300
        print("调用类方法, p_A的值为: {}".format(cls.p_A))
    
    # 类的静态方法中无法调用任何类属性和类方法
    @staticmethod
    def test02():
        # p_C = 400;
        print("调用静态方法")
    
    def test03(self):
        print("实例方法")
        print(self.p_A)


if __name__ == "__main__":
    # 类方法推荐使用类名直接调用，当然也可以使用实例对象来调用（不推荐）
    p = Person()
    Person.test01()
    print(p.p_A)
    # 静态方法的调用，既可以使用类名，也可以使用类对象
    p.test02()
    Person.test02()
    # 在实际编程中，几乎不会用到类方法和静态方法，因为我们完全可以使用函数代替它们实现想要的功能，但在一些特殊的场景中（例如工厂模式中），使用类方法和静态方法也是很不错的选择。
    p.test03()



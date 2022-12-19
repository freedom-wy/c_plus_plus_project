class Base(object):
    def haha(self):
        print("公共方法")


class T1(Base):
    def test1(self):
        print("T1的方法")


class T2(Base):
    pass


if __name__ == "__main__":
    t1 = T1()
    t1.haha()
    t1.test1()

    t2 = T2()
    t2.haha()

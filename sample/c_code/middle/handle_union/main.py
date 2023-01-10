# python下的枚举
# 创建枚举类
from enum import Enum

class Color1(Enum):
    red = 10
    green = 20
    blue = 30

# 通过Enum函数创建枚举类, 值默认为1, 2, 3, 在c++中为0, 1, 2
Color2 = Enum("Color2", ("red", "green", "blue"))


if __name__ == "__main__":
    print(Color1.red, type(Color1.red))
    print(Color1(10), type(type(Color1(10))))
    print(Color1.red.value)
    for c in Color1:
        print(c)
    # Color.red = 10 # 不能修改

    print("##############")

    print(Color2.red.value)
    print(Color2.green.value)
    print(Color2.blue.value)

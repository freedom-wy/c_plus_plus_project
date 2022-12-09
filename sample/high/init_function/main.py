class Person(object):
    def __init__(self):
        print("构造函数")
    
    def __del__(self):
        print("析构函数")


if __name__ == "__main__":
    p = Person()
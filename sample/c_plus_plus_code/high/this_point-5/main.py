class Person(object):
    def __init__(self, age):
        self.age = age
    
    # 返回self, 可以进行链式调用
    def PersonAddPerson(self, p):
        self.age = self.age + p.age
        return self



if __name__ == "__main__":
    p1 = Person(age=10)
    p2 = Person(age=10)
    p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1)
    print(p2.age)
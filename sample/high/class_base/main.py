class Student(object):
    
    def setName(self, name):
        self.name = name
    
    def setCode(self, code):
        self.code = code
    
    def showStudentInfo(self):
        print ("学生姓名为: {}, 学号为: {}".format(self.name, self.code))

if __name__ == "__main__":
    s1 = Student()
    s1.setName("张三")
    s1.setCode(1)
    s1.showStudentInfo()
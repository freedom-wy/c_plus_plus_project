class Point(object):
    def setX(self, x):
        self.p_x = x
    def getX(self):
        return self.p_x
    
    def setY(self, y):
        self.p_y = y
    def getY(self):
        return self.p_y

class Circle(object):
    def setR(self, r):
        self.c_r = r
    def getR(self):
        return self.c_r
    
    def setCenter(self, p):
        self.center=p
    def getCenter(self):
        return self.center

def isInCircle(c, p):
    distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX()-p.getX())+\
    (c.getCenter().getY()-p.getY())*(c.getCenter().getY()-p.getY())

    r_distance = c.getR()*c.getR()

    if distance == r_distance:
        print("点在圆上")
    elif distance < r_distance:
        print("点在圆内")
    else:
        print("点在圆外")

if __name__ == "__main__":
    c = Circle()
    c.setR(10)
    p_circle = Point()
    p_circle.setX(10)
    p_circle.setY(0)
    c.setCenter(p_circle)

    p = Point()
    p.setX(10)
    p.setY(11)

    isInCircle(c, p)
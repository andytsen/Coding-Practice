

class Shape:

    def __init__(self):
        self.id = 1
# END Shape Class

class Circle(Shape):

    def __init__(self,x,y,r):
        self.x = x
        self.y = y
        self.r = r
    
    def is_inside(self, xi, yi):
        dx = (xi - self.x) ** 2
        dy = (yi - self.y) ** 2
        if (dx - dy) < self.r:
            return True
        return False

class Square(Shape):
    
    def __init__(self, x, y, l):
        self.x = x
        self.y = y
        self.l = l

    def is_inside(self, xi, yi):
        if xi > (self.x + (self.l/2)) or xi < (self.x - (self.l/2)):
            return False
        if yi > (self.y + (self.l/2)) or yi < (self.y - (self.l/2)):
            return False
        return True

class Rectangle(Square):




c1 = Circle(0,0,2)

if c1.is_inside(0.5,1):
    print('is inside')

s1 = Square(1,1,2)
if s1.is_inside(1,1):
    print('square is inside')
if s1.is_inside(0.5,1):
    print('square is inside')



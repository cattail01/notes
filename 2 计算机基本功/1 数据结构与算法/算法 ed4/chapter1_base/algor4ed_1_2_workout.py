# coding=utf-8
import random
import math

class NumException(Exception):
    """数据不符合规范异常"""
    def __init__(self, *args: object) -> None:
        super().__init__(*args)
        self.err = args[0]
    def __str__(self) -> str:
        return self.err

"""
algorithm 4ed workout
1.2.1: 单位正方形内创建n个随机点
找出随机点之间的最小距离
"""
class Point:
    """点的数据结构"""
    def __init__(self) -> None:
        self.x = random.random()
        self.y = random.random()



def Point2D(n: int = 0) -> float:
    if n <= 1:
        raise NumException("err: input num <= 1!")

    print("/" * 50)
    lst = []
    for i in range(n):
        lst.append(Point())
        print(lst[i].x, lst[i].y)

    print("/" * 50)
    result_distance = 100
    for i in range(n):
        for j in range(i + 1,n):
            distance = math.sqrt((lst[i].x - lst[j].x)**2 + (lst[i].y - lst[j].y)**2)
            print(distance)
            if result_distance > distance:
                result_distance = distance
    print("/" * 50)
    return result_distance

if True:
    n = 10
    print("\n{:.5f}".format(Point2D(n)))

"""
algorithm 4ed workout
1.2.2 给一堆一维线段，求线段的相交的对
令生成的数值范围在-100 ~ 100之间
"""
class Line:
    def __init__(self) -> None:
        self.x1 = (random.random() - 0.5) * 200
        self.x2 = (random.random() - 0.5) * 200
    def __str__(self) -> str:
        return "" + self.x1 + self.x2

def Interval1D(n: int = 2):
    if n <= 1:
        raise NumException("err: input num <= 1!")
    
    lst = []
    for i in range(n):
        lst.append(Line())
        print(lst[i])
    print()
    
    dirc = dict()
    for i in range(n):
        dirc[i] = []
        for j in range(i + 1, n):
            pass

if True:
    pass

"""
algorithm 4ed workout
1.2.6 回环变位字符串
"""

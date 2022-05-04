### 常用的Python内置装饰器

#### @property

* 作用：像调用类的属性一样调用类的方法

``` python 
# coding: utf-8
class TestClass:
    name = "test"

    def __init__(self, name):
        self.name = name

    @property
    def sayHello(self):
        print "hello", self.name

cls = TestClass("felix")
print "通过实例引用属性"
print cls.name
print "像引用属性一样调用@property修饰的方法"
cls.sayHello
```

#### @staticmethod

* 类中的方法装饰为静态方法
* 类不需要创建实例的情况下，可以通过类名直接引用

```python 
# coding: utf-8
class TestClass:
    name = "test"

    def __init__(self, name):
        self.name = name

    @staticmethod
    def fun(self, x, y):
        return  x + y

cls = TestClass("felix")
print "通过实例引用方法"
print cls.fun(None, 2, 3) # 参数个数必须与定义中的个数保持一致，否则报错

print "类名直接引用静态方法"
print TestClass.fun(None, 2, 3) # 参数个数必须与定义中的个数保持一致，否则报错
```

#### @classmethod

* 类方法的第一个参数是一个类，是将类本身作为操作的方法。类方法被哪个类调用，就传入哪个类作为第一个参数进行操作。


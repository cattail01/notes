### @函数名

> 在xxx函数上方使用了@函数名，在xxx内部会自动执行这个函数名，并且将xxx作为参数传递进去，并将结果赋值给xxx

* xxx = 函数名(xxx)

```python 
def outer(origin):		## 返回一个函数对象
    def inner():		## 模仿origin的行为，并修饰
        print("before")	# 修饰
        res = origin()	# 调用原来的函数
        print("after")	# 修饰
        return res		# 模仿原函数返回行为
    return inner

@outer	# func = outer(func)	# 装饰器
def fuc():
    print("我是fuc函数")
    value = (11, 22, 33, 44)
    return value

result = fuc()
print(result)
```




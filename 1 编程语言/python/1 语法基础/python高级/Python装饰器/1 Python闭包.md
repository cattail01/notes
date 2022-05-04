### Python闭包

```python
'''
题目：需求：请实现在函数执行前输出before
执行后输出after
'''
def fuc():
    print("我是fuc函数")
    value = (11, 22, 33, 44)
    return value

result = fuc()
print(result)

# 实现功能：闭包
def outer(origin):
    def inner():		# 相当于一个原函数
        print("before")	# 执行之前输出
        res = origin()	# 调用原来的函数
        print("after")	# 执行之后输入
        return res
    return inner
func = outer(fuc)	# out()的值是inner函数对象
result = fuc()		# 执行的其实是inner函数
print(result)
```


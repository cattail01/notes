【示例】导入math模块

```python
m = __import__("math")
print(m.pi)
```
```python
import importlib
a = importlib.import_module("math")
print(a.pi)
```
* `importlib.reload()`重新加载模块
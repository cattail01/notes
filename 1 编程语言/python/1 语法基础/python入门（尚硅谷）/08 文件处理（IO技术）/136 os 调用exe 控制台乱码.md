### 136 os 调用exe pycharm控制台乱码
#### 一、os模块
>os模块可以直接对操作系统进行操作，相当于电脑脚本


【示例】os.system调用笔记本程序
```python
import  os
os.system("notepad.exe")
```

【示例】os.system调用ping命令

```python
import os
os.system("start ping github.com")
# 需要加上start
```
【示例】os.startfile命令调用可执行文件

```python
import os
os.startfile("path" + "name.exe")
```

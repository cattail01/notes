### shutil 模块

> 该模块是用来做文件和文件夹的拷贝、移动、删除等，还可以进行文件的压缩和解压

> shutil模块是os模块的一些补充

```
import shutil
shutil.copyfile("路径，文件", "路径，拷贝的文件名")
shutil.copytree("路径", "创建的新路径", ignore=shutil.ignore_patterns("*.py"))  
# 后面的ignore是忽视的文件类型

```

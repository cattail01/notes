### shutil 压缩
```
import shutil
shutil.make_archive("要存放的位置", "压缩的格式", "要压缩的文件")
```

##### 压缩的另一种方法
```
import zipfile
# 压缩
z1 = zipfile.ZipFile("压缩文件存放地址\\压缩文件名.zip", "w")
z1.write("要压缩的文件")
z1.close()

# 解压缩
z2 = zipfile.ZipFile("压缩文件", "a")
z2.extractall("path")
z2.close()
```
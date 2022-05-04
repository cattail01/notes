[toc]

### urllib 网络请求库

#### 网络请求：request

```python
import urllib.request
response urllib.request.urlopen("http://www.baidu.com")
print(sesponse.read().decode("utf-8"))
```

##### urlopen

```python
urllib.request.urlopen (url, data=None, [timeout, ] * )
```

* url：网络地址
* data：post请求数据
* timeout：请求超时的时间

##### request

```python
urllib.request.Request(url, data=None, headers={}, method=None)
```

###### 示例

```python
from urllib import request, parse import ssl
# 使用ssl未经验证的上下文
context = ssl._create_unverified_context()
# 请求使用数据
url = 'https://biihu.cc//account/ajax/login_process/' headers = {
    #假装⾃⼰是浏览器 
    'User-Agent':' Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36',
}
# 定义请求参数
dic = { 'return_url':'https://biihu.cc/', 'user_name':'xiaoshuaib@gmail.com', 'password':'123456789', '_post_type':'ajax', }
# 我们把请求的参数转化为byte
data = bytes(parse.urlencode(dic),'utf-8')
# 封装request
req = request.Request(url, data=data, headers=headers, method='POST')
# 进行请求
response = request.urlopen(req,context=context) print(response.read().decode('utf-8'))
```


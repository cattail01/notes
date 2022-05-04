[toc]

### 13.2.0 拷贝控制和资源管理

#### 对象的两种拷贝语义

* 让对象看起来像指针
  * 拷贝时复制具体的值
  * string、vector等
* 让对象看起来像指针
  * 拷贝时复制指针
  * shared_ptr等
* 都不像
  * unique_ptr

#### 示例类

```C++
class HasPtr{
private:
    int i;
    std::string *ps;
}
```


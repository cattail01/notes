[toc]

### 13.2.1 行为像值的类

#### 示例代码

```C++
class HasPtr{
private:
    std::string *ps;
    int i;
public:
    // 构造函数
    HasPtr(const std::string &s = std::string()):
    	ps(new string(s)), i(0){};	
    // 拷贝构造
    HasPtr(const HasPtr &p):
    	ps(new string(p.s)), i(p.i){};	// 指针成员：创建新的内存并拷贝指针位置的内容	// 值成员：拷贝
    // 重载的赋值运算符
    HasPtr& operator=(const HasPtr &);
    // 析构函数
    ~HasPtr(){delete ps;}	// 注意释放new出来的string *
}
```

#### 编写拷贝运算符的注意事项

* 异常安全
  * 发生异常时，不释放左侧内存
  * 先将参数中的内容拷贝到新位置可以避免异常发生出现严重后果
* 拷贝之前应当先释放this中的值
* 防范自身拷贝
  * 如果delete了自身的指针成员，则无法执行指针拷贝

```C++
HasPtr& HasPtr::operator=(const HasPtr &rhs){
    auto newp = new string(*rhs.ps);	// 创建空间并拷贝指针内容
    delete ps;	// 释放this内存
    ps = newp;
    i = rhs.i;
    return *this;
}
```


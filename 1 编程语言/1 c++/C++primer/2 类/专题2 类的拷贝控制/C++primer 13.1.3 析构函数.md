[toc]

### 13.1.3 析构函数

#### 引入

* 功能：销毁非static对象，并释放内存

* 声明方式

  ```C++
  class Foo{
  public:
      ~Foo();	// 析构函数
  }
  ```

#### 析构函数功能

* 首先执行析构函数体中的内容
* 然后销毁对象本身（按定义逆序销毁成员、销毁对象）

#### 调用析构函数的操作

* 对象被销毁（离开作用域、delete）
* class被销毁时，自动销毁成员，执行成员析构
* 销毁容器和数组时制动销毁对象

#### 合成析构函数

* 一般情况下，自动delete每个成员
* 特殊情况下，阻止对象析构（一般用不到）

#### 对象销毁在析构函数之后
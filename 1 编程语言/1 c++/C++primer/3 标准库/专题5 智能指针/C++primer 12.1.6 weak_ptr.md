[toc]

### 12.1.6 weak_ptr

#### 特性

* 指向shared_ptr
* 和shared_ptr对象本身的管理无关
  * count的数量只和普通拷贝数量有关，和weak_ptr无关

#### 初始化

* 用一个shared_ptr初始化weak_ptr

  ```C++
  // shared_ptr<type> p(new type());
  weak_ptr<type> wp(p);
  ```

#### 访问方式

* 因为不知道该对象是否还存在，所以不能直接访问

* 应当使用lock方法

  ```C++
  if(shared_ptr<type> np != wp.lock()){}
  ```

#### 功能

* 可以检查shared_ptr是否存在

##### 示例：核查指针类（StrBlobPtr）


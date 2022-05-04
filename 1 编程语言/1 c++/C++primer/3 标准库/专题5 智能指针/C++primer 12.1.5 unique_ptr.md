[toc]

### 12.1.5 unique_ptr

#### 特性

* 某时刻，只能有一个unique_ptr类型的指针指向一个对象
* 当unique_ptr被销毁时，该位置上的内存被销毁

#### 初始化

* 绑定到new返回的指针上
* 必须时直接初始化，不能用拷贝初始化（explicate）

```C++
// #include <memory>
unique_ptr<type> uptr(new type());
```

#### 转移（reset、release）

* 不支持拷贝和赋值操作

* 将地址从一个指针转移到另一个指针上

  ```C++
  // unique_ptr<> p2, p3;
  p2.reset(p3.release());	// p3释放，返回地址，p2释放，获得新地址
  ```

* 注意：release不会释放内存

  ```C++
  p3.release();	// 返回地址，结束该地址与p3的绑定，但不会销毁该位置的地址，成为了垃圾（内存在，丢失指针）
  ```

#### 参数传递和返回值

##### 传递参数

```C++
int foo(T2DMatrix const& m);
std::unique_ptr<T2DMatrix> matrixptr;
foo(*matrixptr);
```

##### 返回值

* 可以正常使用，在即将被销毁的情况下允许拷贝

  ```C++
  unique_ptr<type> fuc(){
      return unique_ptr<type>(new type());
  }
  ```

#### deleter for unique_ptr

* 内部删除管理方式与shared_ptr不同

```C++
unique_ptr<connection, decltype(deleter)*> p(&c, deleter);
```


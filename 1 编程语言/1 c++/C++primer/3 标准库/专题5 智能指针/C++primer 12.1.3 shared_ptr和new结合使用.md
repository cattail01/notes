[toc]

### 12.1.3 shared_ptr和new结合使用

#### 介绍

##### 使用方法

```C++
shared_ptr<int> p(new int(42));
```

##### 该构造函数是explicate的

```C++
template< class Y >
explicit shared_ptr( Y* ptr );
```

* explicate：不能用于隐式转换或复制初始化
* 初始化形式：必须是直接初始化
* 返回值形式：必须是 `return shared_ptr(new int(42));`

#### 定义和改变shared_ptr的方法

##### 构造函数

* (q)：指针，指向的对象归shared ptr管理
* (u)：unique ptr，独享变共享
* (q, d)：d是可调用对象，代替delete

##### .reset()

* 功能：将参数指针指向的对象给shared_ptr接管

  ```C++
  shared_ptr<int> p;
  p.reset(new int());	// new创建了一个普通指针，这个指针指向的位置被shared_ptr接管
  ```

* 参数

  * void reset() noexcept;
  * void reset( Y* ptr );
  * void reset( Y* ptr, Deleter d );
  
* 应用方式

  ```C++
  if(!p.unique())	// 如果p不是唯一指向该位置的指针
      p.reset(new string(*p));	// 创建一个p指向对象的副本
  *p += new_value;	// 此时，p指向新位置，改变值不会改变底层共用数据的值
  ```

##### .get()

* 返回shared_ptr类型的普通指针
* 禁止使用.get()赋值给普通变量
* 禁止使用.ger()初始化新的shared_ptr()

##### 注意事项

###### 不要将智能指针和普通指针指向同一个对象

```C++
// fuc(shared_ptr) -> void
int *x(new int(1024));
fuc(shared_ptr<int> (x));	// 当离开fuc函数作用域时，shared_ptr发现引用计数器值为0，便释放对象
// *x = 2048;	// 报错：此时x指向的对象被释放，x变成空悬指针
```

#### 参考资料

##### [C++reference-shared_ptr](https://zh.cppreference.com/w/cpp/memory/shared_ptr/shared_ptr)

##### [C++reference-shared_ptr-reset](https://zh.cppreference.com/w/cpp/memory/shared_ptr/reset)


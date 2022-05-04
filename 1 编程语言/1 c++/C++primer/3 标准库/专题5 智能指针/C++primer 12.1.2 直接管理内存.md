[toc]

### 12.1.2 直接管理内存

#### 引言

* new和delete直接操作内存，建立和销毁堆中的对象

#### 使用new动态分配和初始化对象

* new返回一个指向堆中位置的指针

* 初始化

  * 默认情况下，默认初始化（内置类型初始值不定）
  * 可以使用直接初始化方式初始化对象（值初始化、列表初始化、默认值初始化）

  ```C++
  int *a = new int(42);	// *a == 42
  int *b = new int();		// *b == 0	
  auto *c = new auto(42.5);	// double 42.5
  ```

##### const类型的new

* 可以使用，返回const的顶层指针

```C++
const int *p = new const int(1024);
```

#### 内存耗尽

* include \<new\>

##### 默认情况下，内存耗尽时使用new

* 抛出bad_alloc类型异常

##### 尝试修改，返回nullptr

* `int *p = new(nothrow) int;`

#### 释放动态内存：delete

##### 指针和delete

* delete作用对象：必须时new返回的指针或nullptr
* const指针可以被delete

##### 动态内存生存期直到被释放为止

* new一个对象后，不要忘记delete
* 坚持使用动态分配的内存（如shared_ptr）有利于管理内存

##### delete之后重置指针的值可以提供一定的保护

* delete后，该指针变量指向的位置被销毁，但是该指针变量未消失，变成了指向未知位置的野指针

```C++
delete p;
p = nullptr;	// 可以显示的说明该位置被销毁，不能使用ptr
```


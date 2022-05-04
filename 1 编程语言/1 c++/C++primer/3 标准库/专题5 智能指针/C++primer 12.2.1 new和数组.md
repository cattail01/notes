[toc]

### 12.2.1 new和数组

#### 格式

```C++
// 直接创建
int *a = new int[size];		// 其中，size可以非常量
// 使用数组类型创建
typedef int arrT[42];	// arrT是一个数组类型
int *p = new arrT;
```

#### new type[] 返回 type* 而非数组类型

* 意味着可以直接对其解引用
* 意味着begin和end、范围for不能对其使用

#### 初始化

```C++
int *a = new int[size];	// 默认初始化，内置类型值不定
int *b = new int[size]();	// 默认值初始化，初始化为0
int *c = new int[size]{...};	// 初始化器
```

##### 如果 size<初始化器长度

* 抛出`/*#include <new>*/ bad_array_new_length`异常
* 不能使用auto分配数组

##### 动态分配空数组

* 返回一个尾后指针
  * 可以对该指针进行所有尾指针一样的操作

#### 释放动态数组

* 释放时，数组会按逆向销毁

```C++
delete [] p;
```

#### 智能指针和动态数组

##### unique_ptr

```C++
unique_ptr<int[]> up(new int[10]);
up[0] = 13;
```

##### shared_ptr

* 没有定义动态数组的形式

```C++
shared_ptr<int> sp(new int[10], [](int *p){delete [] p;});	// 必须提供delete[], 否则会执行默认的delete
*(sp.get() + 1) = 13;
```


[toc]

### 12.1.1 shared_ptr类

#### 速览

##### 定义方式

```C++
shared_ptr<string> p1;
shared_ptr<list<string>> p2;
```

##### 使用方式

```C++
if(p1 && p1->empty())
    *p1 = "hi";
```

#### make_shared函数

* 是最安全的定义shared_ptr的方法

##### 使用方式

```C++
// #include <memeory>
// p3是shared_ptr, 指向一个值为42的int位置
shared_ptr<int> p3 = make_shared<int>(42);
// p4指向一个“10个9”的string位置
shared_ptr<string> p4 = make_shared<string>(10, '9');
// auto推断方式(指向一个空的vector<int>容器)
auto p5 = make_shared<vector<int>>();
```

#### shared_ptr拷贝和赋值

##### 引用计数器

* 所有的指向相同位置的shared_ptr公用一个引用计数器
* 拷贝给新指针时，引用计数器+1
* 绑定新对象或者销毁（指向该位置的指针减少时），引用计数器-1
* 当引用计数器为0时，删除（delete）堆中的资源并释放空间

##### 示例

```C++
auto q = make_shared<int>(41);
auto r = make_shared<int>(42);
r = q;	// 将q的值拷贝给r
// 递增q指向的地址的引用计数器
// 递减r指向的地址的引用计数器
// 此时r指向的引用计数器的值为0，销毁，并释放空间
```

#### shared_ptr自动销毁管理的对象并释放内存

##### 析构函数

* 析构函数的功能：对象销毁时执行的函数（自动销毁或delete）
* shared的析构函数会递减引用计数器，如果为0时销毁对象

##### 使用自动生存周期对象管理shared_ptr

* 注意：及时删除shared_ptr指针，有利于防止内存溢出（常见为算法删除而未使用erase或=nullptr）

```C++
shared_ptr<int> fac1(){
    return make_shared<int>(42); 
}
void fuc2(){
    auto p = fac1();	// p: count + 1
}	// p: count - 1; 	// if p: count == 0, delete p(指向的堆中的位置);
```

#### 使用动态生存期资源的类

##### 使用动态生存期对象的原因

* 不知道需要多少对象（多线程）
* 不知道需要的准确类型
* 多个对象间共享底层数据

#### 示例程序

##### 共享底层数据的容器类型

###### 共享底层数据的类定义



##### shared_ptr具体使用示例

```C++
// C++ reference 
// 涉及到多线程知识
#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>

struct Base
{
    Base() { std::cout << "  Base::Base()\n"; }
    // 注意：此处非虚析构函数 OK
    ~Base() { std::cout << "  Base::~Base()\n"; }
};
 
struct Derived: public Base
{
    Derived() { std::cout << "  Derived::Derived()\n"; }
    ~Derived() { std::cout << "  Derived::~Derived()\n"; }
};
 
void thr(std::shared_ptr<Base> p)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::shared_ptr<Base> lp = p; // 线程安全，虽然自增共享的 use_count
    {
        static std::mutex io_mutex;
        std::lock_guard<std::mutex> lk(io_mutex);
        std::cout << "local pointer in a thread:\n"
                  << "  lp.get() = " << lp.get()
                  << ", lp.use_count() = " << lp.use_count() << '\n';
    }
}
 
int main()
{
    std::shared_ptr<Base> p = std::make_shared<Derived>();
 
    std::cout << "Created a shared Derived (as a pointer to Base)\n"
              << "  p.get() = " << p.get()
              << ", p.use_count() = " << p.use_count() << '\n';
    std::thread t1(thr, p), t2(thr, p), t3(thr, p);
    p.reset(); // 从 main 释放所有权
    std::cout << "Shared ownership between 3 threads and released\n"
              << "ownership from main:\n"
              << "  p.get() = " << p.get()
              << ", p.use_count() = " << p.use_count() << '\n';
    t1.join(); t2.join(); t3.join();
    std::cout << "All threads completed, the last one deleted Derived\n";
}

/*
  Base::Base()
  Derived::Derived()
Created a shared Derived (as a pointer to Base)
  p.get() = 0x2299b30, p.use_count() = 1
Shared ownership between 3 threads and released
ownership from main:
  p.get() = 0, p.use_count() = 0
local pointer in a thread:
  lp.get() = 0x2299b30, lp.use_count() = 5
local pointer in a thread:
  lp.get() = 0x2299b30, lp.use_count() = 3
local pointer in a thread:
  lp.get() = 0x2299b30, lp.use_count() = 2
  Derived::~Derived()
  Base::~Base()
All threads completed, the last one deleted Derived
*/
```

#### 参考资料

##### [shared_ptr -- C++reference](https://zh.cppreference.com/w/cpp/memory/shared_ptr)

* [构造函数](https://zh.cppreference.com/w/cpp/memory/shared_ptr/shared_ptr)

##### [make_shared -- C++reference](https://zh.cppreference.com/w/cpp/memory/shared_ptr/make_shared)


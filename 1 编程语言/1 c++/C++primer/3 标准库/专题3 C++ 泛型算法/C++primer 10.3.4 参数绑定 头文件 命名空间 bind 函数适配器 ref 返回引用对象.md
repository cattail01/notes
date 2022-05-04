[toc]

### 10.3.4 参数绑定

#### 引入

* 如果不同地方需要多个可调用对象，最好使用函数而不是写很多个lambda表达式
* 为了使用函数来代替lambda表达式，必须解决lambda的捕获问题

#### 头文件

```C+++
#include <functional>
```

#### [bind函数：函数适配器](https://zh.cppreference.com/w/cpp/utility/functional/bind)

```C++
void test_bind_1(){
    // bind
    // 格式：auto newCallable = bind(callable, arg_list);
    // 功能：实现传入参数的缩小与参数的捕获
    // 原理：当调用newCallable时，调用callable，并依次传递给它arg_list中的参数
    // arg_list中的参数：正常参数，_n占位符，表示传递给newCallable的参数的位置（如_3表示传递给newCallable的第三个参数）
    // 测试：计算1 + 2的值
    using namespace std::placeholders;	// 对：_1，...
    auto f = [](const int &c1,const int &c2){return c1 + c2;};
    auto f_b = bind(f, _1, 2);
    cout << f_b(1);
}
/*
	3
*/
```

##### 使用placehorder名字

```C++
using namespace std::placeholders;
```

##### bind \_n参数 newCallable 与 callable映射原理

```C++
// 假设用g封装f如下
auto g = bind(f, a, b, _2, c, _1);
// 当我们使用g时
g(1, 2);	// _1 = 1, _2 = 2	// _n代表了封装后的参数位置
// 但是实际上调用的是
f(a, b, 2, c, 1);	// bind将arg_list的参数依次传递给f
// 总结：达到了交换参数位置的作用
```

* 示例：使用bind颠倒传参，排序转换

```C++
void test_bind_2(){
    // 测试：使用bind颠倒传参，is_longer由小到大排序
    using namespace std::placeholders;
    vector<int> vec = {1, 2, 3, 4, 5};
    sort(vec.begin(), vec.end(), is_longer<int>);
    for_each(vec.begin(), vec.end(), [](const int &i){cout << i << " ";});
    cout << endl;
    sort(vec.begin(), vec.end(), bind(is_longer<int>, _2, _1));
    for_each(vec.begin(), vec.end(), [](const int &i){cout << i << " ";});
    cout << endl;
}
/*
	5 4 3 2 1 
	1 2 3 4 5
*/
```

#### [ref：绑定引用参数](https://zh.cppreference.com/w/cpp/utility/functional/ref)

* `ref()` `cref()`

```C++
void test_ref_bind_3(){
    // ref：返回参数的引用对象
    // cref：返回参数的const引用对象
    auto f = [](int &a){++a;};
    int a = 0;
    auto f_b = bind(f, ref(a));
    f_b();
    cout << a << endl;
}
/*
	1
*/
```


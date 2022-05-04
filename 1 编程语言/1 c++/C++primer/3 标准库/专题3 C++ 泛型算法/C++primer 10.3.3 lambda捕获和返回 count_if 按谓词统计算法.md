[toc]

### 10.3.3 lambda捕获和返回

* 参考：[C++参考手册-lambda](https://zh.cppreference.com/w/cpp/language/lambda)

#### 值捕获

* 采用值捕获的前提是变量可以被拷贝
* 捕获的变量是在lambda创建时拷贝，而非调用时拷贝

```C++
void test_lambda_4(){
    // 对lambda值捕获进行测试
    // 测试其拷贝时间（创建 or 调用）
    // 创建√
    size_t v1 = 42;
    auto f = [v1]{return v1;};
    v1 = 0;
    cout << f();
}
/*
	42
*/
```

#### 引用捕获

* 在捕获对象前加`&`
* 注意：函数调用时，引用捕获的对象必须存在
* 规范：应当尽量减少捕获的数据量，而且如果有可能的话，尽量避开指针或引用捕获

```C++
void test_lambda_5(){
    // 对lambda引用捕获测试
    // 测试其捕获的对象
    size_t v1 = 42;
    auto f = [&v1]{return v1;};
    v1 = 0;
    cout << f();
}
/*
	0
*/
```

* 函数可以返回lambda表达式
  * 但是返回的lambda中不能有引用捕获

#### 隐式捕获

* 功能：让编译器自动推断需要捕获的对象
* 形式：捕获列表中加=或&

```C++
void test_lambda_6(){
    // 测试：lambda表达式的隐式捕获
    int v1 = 42;
    // 隐式值捕获
    auto f1 = [=](){return v1;};
    // 隐式引用捕获
    auto f2 = [&](){return v1;};
    v1 = 0;
    cout << "f1="<< f1() << endl << "f2=" << f2() << endl;
}
/*
	f1=42
	f2=0
*/
```

#### 混合使用隐式捕获和显式捕获

* 第一个符号必须是默认的捕获方式（=/&）
* 混合使用时，显示捕获必须与默认方式不同

```C++
void test_lambda_7(){
    // 测试：lambda表达式的混合捕获
    int v1 = 1, v2 = 2;
    auto f1 = [=, &v2](){cout << v1 << " " << v2 << endl;};
    auto f2 = [&, v2](){cout << v1 << " " << v2 << endl;};
    f1();
    f2();
    v1 = v2 = 0;
    f1();
    f2();
}
/*
	1 2
	1 2
	1 0
	0 2
*/
```

#### 可变lambda

* 值捕获的情况下，如果希望修改捕获的变量的值，必须加mutable（而且被捕获的变量本身并不会改变）
* 引用捕获的情况下，是否可以改变元素取决于该对象定义是否为const

```C++
void test_lambda_mutable_8(){
    // 测试：可变的值捕获：mutable
    int v1 = 42;
    auto f1 = [v1]()mutable{cout << ++v1 << endl;};
    auto f2 = [&](){cout << ++v1 << endl;};
    v1 = 0;
    cout << v1 << endl;
    f1();
    f2();
    cout << v1 << endl;
}
/*
	0
	43
	1
	1
*/
```

#### 指定lambda的返回类型

```C++
void test_lambda_9(){
    // 测试：当lambda推断的返回类型错误时指定返回类型
    // 注意：此处必须指定返回值（无法自动推断）
    auto f = [](int i)->int{if(i > 0) return i; else return -i;};
    cout << f(-1) << " " << f(2) << endl;
}
/*
	1 2
*/
```

### 练习题

#### count_if算法：按谓词统计

```C++
/*10.3.3 节练习*/
// 10.20
void test_count_if_1(){
    // count_if
    // 功能：按需求计数
    // 参数：迭代器范围，谓词
    // 返回值：整数，表示多少次谓词为true
    vector<int> vec = {1, 2, 3, 4, 5, 6};
    int count = count_if(vec.begin(), vec.end(), [](const int &a){return !(a % 2);});
    cout << count << endl;
}
/*
	3
*/
```


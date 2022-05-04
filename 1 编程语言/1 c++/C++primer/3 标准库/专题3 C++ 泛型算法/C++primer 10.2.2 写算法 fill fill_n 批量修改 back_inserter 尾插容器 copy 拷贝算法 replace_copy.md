[toc]

### 10.2.2 写算法

* 写算法只是改变容器中的元素，并不会添加或者删除

#### [fill：范围内批量修改元素](https://zh.cppreference.com/w/cpp/algorithm/fill)

```C++
void test_fill_1(){
    // fill
    // 功能：将范围内的元素的值修改为第三个元素的值
    // 参数：迭代器范围、值
    vector<int> *vec = new vector<int>(10);

    // 将迭代器的全部变成0；
    fill(vec->begin(), vec->end(), 0);
    // 将迭代器的前半部分变成10；
    fill(vec->begin(), vec->begin() + vec->size() / 2, 10);
    
	// 输出
    for(auto i : *vec){
        cout << i << " ";
    }
    cout << endl;
}
/*
	10 10 10 10 10 0 0 0 0 0
*/
```

#### [fill_n 改变开始后面n个元素的值](https://zh.cppreference.com/w/cpp/algorithm/fill_n)

```C++
void test_fill_n_1(){
    // fill_n
    // 功能：将范围内的元素的值修改为第三个元素的值
    // 参数：迭代器、改变的数量、值
    // 注意：要确保容器从第一个参数开始有第二个参数的数量的元素
    vector<int> *vec = new vector<int>(10);

    // 将迭代器的全部变成0；
    fill_n(vec->begin(), 10, 0);
    // 将迭代器的前半部分变成10；
    fill_n(vec->begin(), 5, 10);

    for(auto i : *vec){
        cout << i << " ";
    }
    cout << endl;
}
/*
	10 10 10 10 10 0 0 0 0 0
*/
```

#### [back_inserter 获取尾插迭代器](https://zh.cppreference.com/w/cpp/iterator/back_inserter)

```C++
#include <iterator>
void test_back_inserter_1(){
    // iterator header
    // back_inserter()
    // 功能：特殊的函数，返回一个尾插迭代器
    // 参数：容器的引用类型
    // 返回：返回一个插入（inserter）迭代器，
    // 向该迭代器赋值会调用容器的push_back方法，并自动向后移动一位
    // 测试：将尾插迭代器与修改迭代器(fill_n)连用，使其能够插入预设的值
    vector<int> vec;
    
    // 使用fill_n向vec的后面插入10个0；
    fill_n(back_inserter(vec), 10, 0);
    
    for(auto i : vec){
        cout << i << " ";
    }
}
/*
	0 0 0 0 0 0 0 0 0 0
*/
```

#### [copy 拷贝算法](https://zh.cppreference.com/w/cpp/algorithm/copy)

```C++
void test_copy_1(){
    // copy
    // 功能：拷贝前面的范围到后面的序列内
    // 参数：迭代器范围、要拷贝位置的开始迭代器
    // 返回值：返回一个迭代器
    vector<double> vec = {1.1, 2, 3, 4, 5};
    vector<double> *vec_2 = new vector<double>((int)vec.size() + 1);
    auto result = copy(vec.begin(), vec.end(), vec_2->begin());
    vec_2->push_back(12);
    for(auto i : *vec_2){
        cout << i << " ";
    }
    cout << endl << *result << endl;
}
/*
	1.1 2 3 4 5 0 12 
	0
*/
```

#### [replace replace_copy](https://zh.cppreference.com/w/cpp/algorithm/replace_copy)

```C++
void test_replace_copy_1(){
    // replace
    // 功能：替换容器中的元素
    // 参数：迭代器范围、被替换的元素、新元素
    // 返回值：void
    // replace_copy
    // 功能：replace的copy版本（很多算法都有copy版本）
    // 参数：第三个新增了要拷贝到的开始位置
    const vector<int> vec = {1, 2, 3, 4, 5};
    vector<int> *vec_copy = new vector<int>(10);
    replace_copy(vec.begin(), vec.end(), vec_copy->begin(), 1, 0);
    for(auto i : *vec_copy){
        cout << i << " ";
    }cout << endl;
}
/*
	0 2 3 4 5 0 0 0 0 0 
*/
```

#### 练习

```C++
// 10.7
void test_gaicuo_10_7_1(){
    /*测试数据：1 2 3 4 5 6*/
    vector<int> vec; list<int>list; int i;
    while(cin >> i){
        list.push_back(i);
    }
    // copy(list.begin(), list.end(), vec.begin());
    /*cc1plus.exe: out of memory allocating 65536 bytes*/
    copy(list.cbegin(), list.cend(), back_inserter(vec));
    /*1 2 3 4 5 6*/
    for_each(vec.begin(), vec.end(), [](const int &a){cout << a << " ";});
}
```


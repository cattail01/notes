[toc]

### 只读算法

* 只读取容器中（迭代器指向的范围）中的元素，而不改变元素

#### accumulate 自增算法

```C++
void test_accumulate_1(){
    // numeric header
    // accumulate:
    // 功能：对范围内的数进行求和，并与第三个参数累加
    // 返回：范围内和基础数值的和
    // 注意：第三个参数的特点：其类型必须能够识别+=符号
    vector<int> vec = {1, 2, 3, 4, 5};
    int sum = accumulate(vec.begin(), vec.end(), 0);
    cout << "1 到 5 的和为：" << sum << endl;
    string str = "cattail";
    // 不能使用，因为char*类型字符串不支持+=自增长操作
    // string result = accumulate(str.begin(), str.end(), "");
    // 但是string支持+=操作，所以可以写成：
    string result = accumulate(str.begin(), str.end(), string(""));
    cout << result << endl;
}
/*
	1 到 5 的和为：15
	cattail
*/
```

##### 第三个参数的重要性

* 第三个参数是累加（+=）的基础，其类型也是返回值类型。

```C++
void test_accumulate_2(){
    // 测试：accumulate第三个参数为小范围类型时，返回值能否为大范围类型
    // 测试结果：不能
    vector<double> vec = {1.1, 2, 3, 4, 5};
    double result = accumulate(vec.cbegin(), vec.cend(), 0);
    cout << result << endl;
}
/*
	15(int)
*/
```

#### equal 比较相等算法

```C++
void test_equal_1(){
    // equal:
    // 功能：用于确定两个容器中的内容是否相同
    // 特点：容器类型可以不相同，第二个容器至少比第一个大
    // 参数：第一个容器的迭代器范围；第二个容器的开始比较位置
    // 返回值：true 或 false
    string a = "cat";
    string b = "cattail";
    cout << a << "和" << b << "的比较是否相同？" 
        << (equal(a.begin(), a.end(), b.begin())?
        "相同":"不相同") << endl;
}
/*
	cat和cattail的比较是否相同？相同
*/
```


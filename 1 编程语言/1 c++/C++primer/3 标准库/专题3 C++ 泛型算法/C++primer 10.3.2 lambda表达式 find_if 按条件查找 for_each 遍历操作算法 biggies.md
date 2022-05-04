[toc]

### 10.3.2 lambda表达式

#### [find_if算法：按条件查找](https://zh.cppreference.com/w/cpp/algorithm/find)

```C++
void test_find_if_1(){
    // find_if
    // 功能：返回范围内第一个符合最后一个参数条件的迭代器
    // 参数：迭代器范围，可调用对象
    // 返回：目标的迭代器
    vector<int> vec = {1, 2, 3, 4, 5};
    auto addr = find_if(vec.begin(), vec.end(), [](const int &a){return a > 3;});
    cout << *addr << endl;
}
/*
	4
*/
```

#### [lambda表达式](https://zh.cppreference.com/w/cpp/language/lambda)

##### 可调用对象

* 可以使用调用运算符的对象
* 函数、函数指针、重载了函数调用运算符的类、lambda表达式

##### lambda表达式

```C++
void test_lambda_1(){
    // lambda
    // 格式：[捕获列表](参数列表)->返回类型{函数体}
    // 可删：参数列表，返回类型
    auto f = []{return 42;};
    cout << f() << endl;
}
/*
	42
*/
```

##### 向lambda传递参数

```C++
void test_lambda_2(){
    // 测试：向lambda传参
    // 功能：使用lambda代替is_longer函数功能
    vector<int> vec = {1,2,3,4,5};
    stable_sort(vec.begin(), vec.end(), [](const int &a, const int &b){return a > b;});
    for(auto i : vec)   cout << i << " ";
    cout << endl;
}
/*
	5 4 3 2 1
*/
```

##### 使用lambda捕获列表

```C++
void test_lambda_3(){
    // 测试：使用lambda捕获列表
    vector<int> vec = {1, 2, 3, 4, 5};
    int num = 3;
    auto addr = find_if(vec.begin(), vec.end(), [num](const int &a){return a > num;});
    cout << *addr << endl;
}
/*
	4
*/
```

#### [for_each：遍历并操作算法](https://zh.cppreference.com/w/cpp/algorithm/for_each)

```C++
void test_for_each(){
    // for_each
    // 功能：对范围内的元素执行指定操作
    // 参数：迭代器范围，可调用对象
    // 返回值：第三个参数
    vector<int> vec = {1, 2, 3, 4, 5};
    for_each(vec.begin(), vec.end(), [](const int &i){cout << i << " "; });	// 注意：此处cout无需捕获（全局类型）（参考C++参考手册-语法-解释-捕获）
}
/*
	1 2 3 4 5 
*/
```

#### 完整的biggies

```C++
void biggies_1(vector<string> &words, vector<string>::size_type sz){
    // 输出满足长度的单词
    // 字典排序，删除重复单词
    sort(words.begin(), words.end());
    auto end = unique(words.begin(), words.end());
    words.erase(end, words.end());
    // 长度排序，长度相同的单词保持顺序
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b){return a.size() < b.size();});
    // 获取迭代器，指向第一个满足size() >= sz的元素
    auto first = find_if(words.begin(), words.end(), [sz](const string &a){return a.size() >= sz;});
    // 计算满足条件的数目
    auto count = words.end() - first;
    cout << count << " word" << (count > 1 ? "s" : "") << " of length " << sz << " or longer" << endl;
    // 打印符合条件的单词
    for_each(words.begin(), words.end(), [](const string &a){cout << a << " ";});
    cout << endl;
}
```


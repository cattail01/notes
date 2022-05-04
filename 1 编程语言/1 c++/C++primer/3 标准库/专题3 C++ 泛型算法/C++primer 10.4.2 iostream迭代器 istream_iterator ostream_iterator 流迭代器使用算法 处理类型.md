[toc]

### 10.4.2 iostream迭代器

* 迭代器将io流作为特殊元素序列处理
* 可以使用泛型算法向其中写入数据

#### [istream_iterator 操作](https://zh.cppreference.com/w/cpp/iterator/istream_iterator)

* istream_iterator\<type\>
* 可以绑定到一个流，也可以默认初始化为尾后迭代器

```C++
// 从cin读取int
istream_iterator<int> int_it(cin);
// 尾后迭代器
istream_iterator<int> int_eof;
// 从文件流中读取字符串
ifstream in("a file");
istream_iterator<int> str_it(in);
```

##### 例子

```C++
void test_istream_iterator_1(){
    // 从cin读取int型字符
    istream_iterator<int> in_iter(cin);
    // 设置尾后迭代器
    istream_iterator<int> eof;
    vector<int> vec;
    // 当还能读取时(没有达到尾后)，放入容器中
    while (in_iter != eof){
        vec.push_back(*in_iter ++);
    }
    for_each(vec.begin(), vec.end(), [](const int &a){cout << a << " ";});
}
/*
	1 2 3 4 5
	^Z
	1 2 3 4 5 
*/
```

```C++
void test_istream_iterator_2(){
    // 上面的程序的重写版本
    istream_iterator<int> in_ter(cin), eof;
    vector<int> vec(in_ter, eof);
        for_each(vec.begin(), vec.end(), [](const int &a){cout << a << " ";});
}
/*
	1 2 3 4 5
	^Z
	1 2 3 4 5 
*/
```

#### 使用算法操作流迭代器

```C++
void test_istream_iterator_algorithm_1(){
    // 测试：算法和流迭代器同时使用
    istream_iterator<int> in(cin), eof;
    cout << accumulate(in, eof, 0);
}
/*
	1 2 3 4 5
	^Z
	15
*/
```

#### istream_iterator允许使用懒惰求值

* 使用迭代器的输入流不会立即被读取
* 当两个不同的对象同步读取一个流时会有影响

#### [ostream_iterator 操作](https://zh.cppreference.com/w/cpp/iterator/istream_iterator)

* 对象构建
  * ostream_iterator out(os);
  * ostream_iterator out(os, after);
* 操作
  * out = val：调用<<，输出val
  * 其他操作：支持，但没有作用

```C++
void test_ostream_iterator_1(){
    // 测试：输出流迭代器功能
    vector<int> vec = {1, 2, 3, 4, 5};
    // 定义迭代器，并设置间隔输出
    ostream_iterator<int> out(cout, " ");
    for(auto &a : vec){
        // 解引用和递增可忽略 *out++ = a;	// 效果相同
        out = a;	// 但是推荐上面的形式
    }
    cout << endl;
}
/*
	1 2 3 4 5 
*/
```

```C++
// 上面for循环的升级（融合copy算法）
copy(vec.begin(), vec.end(), out);
```

#### 使用流迭代器处理类型

* 理论上来说，只要能使用流运算符的对象，都能使用流迭代器


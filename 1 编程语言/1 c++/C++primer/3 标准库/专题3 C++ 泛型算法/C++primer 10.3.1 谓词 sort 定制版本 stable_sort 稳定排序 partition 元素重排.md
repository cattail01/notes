[toc]

### 10.3.1 向算法传递函数（谓词）

#### [谓词](https://blog.csdn.net/caroline_wendy/article/details/15378055)

* 谓词是一个表达式，返回值是一个bool类型。
* 分类
  * 一元谓词：接受一个参数
  * 二元谓词：接受两个参数
  * 三元谓词：接受三个参数
* 例如，sort接受一个二元谓词，sort算法本身传递给这个谓词两个参数去比较大小，如果谓词返回true则交换这两个参数的位置

#### 接受谓词的sort

```C++
template<typename T>
bool is_longer(const T &num1, const T &num2){
    return (num1 > num2);
}

void test_sort_2(){
    // 测试：接受谓词的sort函数（是一个重载版本）
    vector<int> vec = {1,2,3,4,5};
    sort(vec.begin(), vec.end(), is_longer<int>);	// 这个地方必须带<int>不知道为什么
    	// 以后如果在看到记得填补空缺
    for(auto i : vec)   cout << i << " ";
    cout << endl;
}
/*
	5 4 3 2 1
*/
```

#### stable_sort稳定的排序算法（及其谓词版本测试）

```C++
void test_stable_sort_1(){
    // stable_sort
    // 功能：稳定的排序方法
    // 参数、返回值：类似与sort函数
    // 测试：接受谓词的stable_sort函数（是一个重载版本）
    vector<int> vec = {1,2,3,4,5};
    stable_sort(vec.begin(), vec.end(), is_longer<int>);
    for(auto i : vec)   cout << i << " ";
    cout << endl;
}
/*
	5 4 3 2 1
*/
```

#### [partition 元素重排算法](https://zh.cppreference.com/w/cpp/algorithm/partition)

```C++
/*10.3.1 节练习*/
// 10.13 partition算法
void test_partition_1(){
    // partition
    // 功能：将符合谓词的元素前置
    // 参数：迭代器范围，谓词
    // 返回值：迭代器，指向最后一个使谓词为true之后的谓词
    vector<string> words = {"i", "am", "a", "good", "people"};
    auto end = partition(words.begin(), words.end(), [](const string &str){return str.size() >= 4;});
    words.erase(end, words.end());
    for_each(words.begin(), words.end(), [](const string &str){cout << str << " ";});
}
/*
	people good 
*/
```


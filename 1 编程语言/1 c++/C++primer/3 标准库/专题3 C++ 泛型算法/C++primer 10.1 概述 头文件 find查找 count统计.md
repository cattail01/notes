[toc]

### 10.1 泛型算法概述

* 不直接操作容器、使用迭代器访问元素
* 适用于任何类型的容器（包括数组），适用于可以执行该算法操作的所有元素类型

#### 头文件

```c++
// 泛型算法常用头文件
#include <algorithm>
#include <numeric>
```

#### find：查找算法

```C++
// 对find()查找算法进行测试
void test_find_1(){
    // find：
    // 参数：迭代器范围、要查找的值
    // 如果找到，则返回找到的迭代器
    // 如果找不到，则返回尾后迭代器
    vector<int> vec = {1, 2, 3, 4, 5};
    int val1 = 2;
    int val2 = 6;
//////////////////////////
    auto result1 = find(vec.begin(), vec.end(), val1);
    auto result2 = find(vec.begin(), vec.end(), val2);
//////////////////////////
    cout << "the value" << val1 << (result1 == vec.end() ? " is not present" : " is present") << endl;
    cout << "the value" << val2 << (result2 == vec.end() ? " is not present" : " is present") << endl;
}
/*
	the value2 is present
	the value6 is not present
*/
```

#### count：统计算法

```C++
// 10.1 count：统计迭代器范围中出现指定值的数量
void test_count_1(){
    vector<int> vec = {2,0,1,9,0,2,0,4,4,2,2,1};
    int val1 = 2;
    int val2 = 3;
///////////////////////////////////////////////////////////
    auto result1 = count(vec.begin(), vec.end(), val1);
    auto result2 = count(vec.begin(), vec.end(), val2);
////////////////////////////////////////////////////////////
    cout << val1 << " 在序列中的个数为：" << result1 << endl;
    cout << val2 << " 在序列中的个数为：" << result2 << endl;
}
/*
	2 在序列中的个数为：4
	3 在序列中的个数为：0
*/

// 10.2 count：统计string中出现字符的个数
void test_count_2(){
    string str = "cattail";
    char a = 't';
    cout << "t在cattail中的个数为：" << count(str.begin(), str.end(), a) << endl;
}
/*
	t在cattail中的个数为：2
*/
```


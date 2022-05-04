[toc]

### 10.4.3 反向迭代器

* 容器（除了forward_list）均支持反向迭代器
* [rbegin, crbegin](https://zh.cppreference.com/w/cpp/iterator/rbegin), [rend, crend](https://zh.cppreference.com/w/cpp/iterator/rend)

```C++
void test_reverse_iterator_1(){
    // 测试：反向迭代器
    vector<int> vec{1, 2, 3, 4, 5};
    for(auto iter = vec.crbegin(); iter != vec.crend(); iter++){	// 注意：此处是++
        cout << *iter << " ";   // 反向输出
    }
    cout << endl;
}
/*
	5 4 3 2 1 
*/
```

#### 反向迭代器需要递减运算符

* 反向迭代器只支持 `--`运算符的迭代器（所以流迭代器和forward_list不能使用）

#### 反向迭代器变成正向迭代器：.base()

`ritem.base()`：将反向迭代器变成正向迭代器（指向会向后移动一位）


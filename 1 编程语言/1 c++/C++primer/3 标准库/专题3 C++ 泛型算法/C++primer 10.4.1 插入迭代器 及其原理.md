[toc]

### 10.4 插入迭代器

#### 插入迭代器支持的操作

* it=t：插入操作
* 其他操作存在，但是没有用

#### 插入迭代器

* 注意：只有方法中支持这种操作才能使用

```C++
// 插入迭代器
back_inserter();
// 参数：容器；返回：尾插迭代器
front_inserter();
// 参数：容器；返回：头插迭代器
inserter();
// 参数：容器、插入位置迭代器；返回：插入位置的后面位置迭代器
```

#### 插入迭代器原理

```C++
auto it = inserter(c, iter);
// 以下的代码
*it = val;
// 的本质是这段代码
it = c.insert(c, val);	// it指向新的元素，以前的元素后移
++it;	// 递增it的值，指向以前的元素
```

#### 测试

```C++
void test_inserters_1(){
    // 探究：inserters的操作原理
    vector<int> old {1, 2, 3, 4, 5};
    list<int> list1, list2;
    copy(old.begin(), old.end(), front_inserter(list1));
    copy(old.begin(), old.end(), inserter(list2, list2.begin()));
    auto f = [](const int &a){cout << a << " ";};
    for_each(list1.begin(), list1.end(), f);
    cout << endl;
    for_each(list2.begin(), list2.end(), f);
}
/*
	5 4 3 2 1 
	1 2 3 4 5
*/
```


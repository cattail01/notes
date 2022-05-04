[toc]

### 10.2.1 定义关联容器

#### 关联容器的定义方式

* 默认构造函数，生成空的关联容器
* 关联容器构造时拷贝初始化
* 从值范围来初始化关联容器
* 新标准，直接初始化
  * set：可以直接用{}括起来
  * map：{{key，value}，{key, value}，...}

#### 初始化multimap或multiset

* multimap和multiset允许key重复

```C++
void difference_between_multi_and_not(){
    // 测试：multi版本和普通版本的区别
    vector<int> vec = {1, 1, 2, 2};
    set<int> iset(vec.begin(), vec.end());
    multiset<int> miset(vec.begin(), vec.end());

    cout << vec.size() << endl;
    cout << iset.size() << endl;
    cout << miset.size() << endl;
}
```


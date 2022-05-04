[toc]

### 11.3.5 访问元素

#### 关联容器中查找元素的方法

* find：查找到第一个关键字为k的元素，并返回迭代器
* count：统计出现key的次数
* lower_bound(upper_bound)：返回指向不小于（大于）key的迭代器
* equal_range：返回pair，first和second为关键字等于key的范围，如果没有则都指向end

#### 对map使用find

* 如果希望查找key是否在map中而不是修改map，请使用find算法

```C++
map.find(key)->second;
// 约等于map[key]，但是不会向内部插入key
```

#### 在multi中查找key

* 最直观的方法：count和find联用

```C++
string search_item = "...";
auto entries = authors.count(search_item);
auto iter = authors.find(search_item);
// 循环查找此作者的所有著作
while(entries){
    cout >> iter->second >> endl;
    ++iter;	// 相同的key必定是连续的
    -- erntries;
}
```

* 面向迭代器的方法：lower_bound指向第一个key出现的位置，upper_bound指向最后一个key的后面
  * 如果该key不存在，则同时指向不影响插入的位置
  * 也就是说，如果返回了相同的迭代器，则key不在map中

```C++
// 上面程序的新版本
for(auto beg = authors.lower_bound(search_item), end = authors.upper_bound(search_item);
   		beg != end; ++beg)
    cout << beg->second >> endl;
```

#### equal_range函数

* 返回一个pair
  * 如果key存在，则返回key的范围
  * 如果不存在，则返回相同的值，即一个可插入范围

```C++
for(auto pos = anthors.equal_range(search_item); pos.first != pos.second; pos.first++){
    cout << pos.first->second << endl;
}
```


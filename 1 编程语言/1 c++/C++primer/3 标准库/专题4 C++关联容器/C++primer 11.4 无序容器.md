[toc]

### 11.4 无序容器

* 使用hash函数和==管理元素
* 无序容器通常有更好的性能

#### 使用无序容器

* 可以将有序容器直接替换为无序容器（无序容器支持有序容器的所有方法）
* 输出的顺序可能会不同（无序输出）

#### 管理桶

* 无序容器的底层原理
  * 桶排序 + 哈希表示桶的标签
  * 如果允许相同的key，则相同key的元素在一个桶中
* 无序容器的性能指标：哈希函数的质量、桶的数量大小
* 无序容器管理操作
  * 略，用到时再记笔记

#### 无序容器对关键字类型的要求

* 默认情况下key应当支持==运算符和hash函数
* 自定义运算和hash的方法

```C++
size_t hasher(const type &a){
    return hash<type>(a);
}
bool epoq(const type &b, const type &c){
    return b == c;
}
```

```C++
using sd_multiset = unordered_multiset<type, decltype(hasher)*, decltype(epoq)*>;
sd_multiset sets(42/*桶大小*/, hasher, epoq);
```


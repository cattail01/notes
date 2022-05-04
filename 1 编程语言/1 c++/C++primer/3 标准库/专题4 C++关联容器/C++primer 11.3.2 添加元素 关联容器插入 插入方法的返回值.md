[toc]

### 11.3.2 添加元素

#### insert特殊插入方法

* 插入重复的元素对非multi版本的关联容器没有影响（只有第一个出现的才能被插入）

```c++
set.insert(vec.begin(), vec.end());	// 接受迭代器范围版本
set.insert({...});	// 接受初始化列表版本
```

* 关联容器的insert和emplace操作
  * insert：value_type对象，b,e迭代器范围，{}，begin ，value_type
  * emplace：args，begin,args

#### 向map添加元素

* value_type：pair
  * make_pair(v1, v2)
  * pair<type1, type2>(v1, v2)
  * map<type1, type2>::value_type(v1, v2)

#### 检测关联容器insert的返回值

* 添加单一元素的插入语句返回一个pair类型
  * first表示插入的迭代器的位置
  * second，bool，表示是否插入成功

#### multi-关联容器 插入操作的返回值

* 返回插入的目标位置的迭代器


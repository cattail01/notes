[toc]

### 11.2.3 pair类型

#### 头文件

* utility

#### 定义pair类型

```C++
pair<type1, type2> var;
```

* 注意：
  * 默认情况下，当定义一个pair类型的对象时，内部数据会进行值初始化
  * 也可以为其提供初始化器`{value1, value2}`

#### 使用pair类型

* pair对象的数据是public的，为first和second

#### pair的其他操作

* make_pair(v1, v2)：返回一个被初始化的pair类型
* p1 role p2 (role 是比较运算符)：两个pair对象中first或者second任意一组符合运算符返回true

#### 返回值是列表初始化

* 新标准

```C++
// 返回pair类型的函数
pair<string, int>
fuc(){
    // 可以直接返回一个列表初始化
    return {v1, v2}
}
```

#### 练习题


[toc]

### 11.3.4 map的下标操作

* set不支持下标和at
* count不支持下标和at
* map的下标操作
  * map[key]：返回key对应的value；如果key不存在，则创建key，并初始化或默认初始化
  * map.at(key)：如果key不在map中，抛出异常`out_of_range`；如果存在则返回对应value

#### 使用下标操作的返回值

* 返回一个该位置上的mapped_type的左值，可以直接用来修改该位置的元素

```C++
++vord_count["Anna"];	// 将Anna对应的value自增1
```


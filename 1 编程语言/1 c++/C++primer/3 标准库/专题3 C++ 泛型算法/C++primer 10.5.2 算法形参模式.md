[toc]

### 10.5.2 算法形参模式

```C++
alg(beg, end, other args);
alg(beg, end, dest, other args);
alg(beg, end, beg2, other args);
alg(beg, end, beg2, end2, other args);
```

* beg, end：算法的输入范围
* dest，beg2， end2：算法执行的操作
* other args：其他操作

#### 接受单个目标迭代器的算法

* dest：容器或插入迭代器
* 算法假定：dest为容器时，有足够的空间
* 常见的dest情况：插入迭代器 或 输出流迭代器（保证空间足够）

#### 接受第二个输入序列的算法

* 接受单独的beg2或者接受beg2和end2的算法表示接受第二个输入范围
* 接受单独的beg2的算法默认至少和第一个范围一样大


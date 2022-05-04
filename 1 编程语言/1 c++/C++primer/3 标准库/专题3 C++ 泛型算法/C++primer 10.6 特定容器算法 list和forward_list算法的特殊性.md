### 10.6 特定容器算法

* list和forward_list只提供双向和前向迭代器，

* 常用算法被封装在该类型的class内部作为方法使用

  如：sort、merge、remove、reverse、unique

  而且与算法不同，方法可以直接操作容器而非位置

* 其他算法可以被使用在这两个容器类型上，但是代价有点高

  所以应当优先使用成员版本的算法而不是algorithm内的函数

#### splice成员

* 拼接操作，将list中的元素（或其中的指定位置）插入指定list中，并销毁list中被移动的元素


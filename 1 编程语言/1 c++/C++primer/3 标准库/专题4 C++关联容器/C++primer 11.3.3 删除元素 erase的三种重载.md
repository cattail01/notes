[toc]

### 11.3.3 删除元素

#### erase的三种重载

```C++
// set<type> sets;
sets.erase(iter);	// ->void	// 接受一个目标位置迭代器
sets.erase(beg, end);	// ->void	// 接受一个迭代器范围
// 新方法
sets.erase(key);	// -> int	// 接受查找的key值，返回删除的个数	// 普通返回0或1，multi版本返回int
```


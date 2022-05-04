[toc]

### 12.2.2 allocator类

#### 引入

* 控制内存分配，使内存占有和对象构造独立
* 先圈出要使用的内存，再在其中创建

#### allocator类

##### 介绍

* #include \<memory\>
* 功能：按照提供的类型划分出原始的、未构造的内存

##### 使用方式

* 定义方式

  ```C++
  allocator<string> alloc;	// 可以分配string的allocator对象
  auto const p = alloc.allocate(n);	// 划分了n个string占用的原始空间
  ```

* 分配方式：construct

  ```C++
  auto q = p;		// 创建一个可以移动的尾后指针
  alloc.construct(q++);	// 在q的位置上创建对象，并让q指向尾后指针
  alloc.construct(q++, args);	// args包含初始化信息
  ```

* 销毁方式：destroy

  ```C++
  while(q != p)
      alloc.destroy(--q);
  ```

* 销毁allocator：deallocate

  ```C++
  alloc.deallocate(p, n);	
  // p是指向alloc.allocate创建位置的的指针
  // n是创建的大小
  // 需要一摸一样
  ```

##### allocator 拷贝和填充 未分配的内存 算法

* uninitialized_（friend functions）（参数同algorithm::copy & ::fill）

  * copy
  * copy_n
  * fill
  * fill_n

* 示例

  ```C++
  auto p = alloc.allocate(vec.size() * 2);
  auto q = uninitialized_copy(vec.begin, vec.end, p);	// 将vec中的内容拷贝到allocator类创建的内存中
  uninitialized_n(q, vec.size(), 42);	// 填充为42
  ```


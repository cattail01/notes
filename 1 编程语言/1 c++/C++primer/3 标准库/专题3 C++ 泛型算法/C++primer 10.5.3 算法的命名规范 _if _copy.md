### 10.5.3 算法的命名规范

#### 传递谓词：重载还是_if

* 如果算法本身只接受两个参数（如排序算法sort），无需第三个参数（如指定元素，指定大小之类的），

  则使用重载方法（sort(begin, end, [callable])）

* 如果算法接受第三个参数（如查找算法find），为了防止函数（谓词）类型和第三个参数类型发生重载冲突，

  应当使用_if命名(find_if(begin, end, callable))

#### 修改位置：直接写回还是_copy

* 默认情况下，修改位置的算法默认写回
* _copy版本算法将结果拷贝给新位置，并保持原来位置元素不变


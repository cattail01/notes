[toc]

### 11.1 使用关联容器

#### 关联容器简介

* map：下标不必是位置，也可以是键
* set：关键字的简单集合，可以快速识别键是否存在

#### 使用map

##### 定义map

```C++
map<key_type, value_type> map_var;
```

##### 使用map，添加或者修改map的元素

```C++
map_var[key] = value;	// 如果有就修改，如果没有则添加元素
```

##### 使用map的元素（直接使用内部对象方法）

```C++
for(auto/*pair*/ &a : map_var){
    use(a.first);
    use(a.second);
}
```



##### 示例：统计单词出现的次数

```C++
void count_words(){
    // 对map的常见使用进行测试
    // 定义
    map<string, size_t> word_count;
    string word;
    while(cin >> word)
        // 向其中添加元素或者操作元素
        ++word_count[word];
    for(const auto &w : word_count){
        // 使用其中的值
        cout << w.first << " occurs " << w.second 
            << (w.second > 1 ? " times" : "time");
    }
}
```

#### 使用set

##### 示例：统计非指定单词出现的次数

```C++
void count_words_2(){
    // 对set的简单实用进行测试
    // 函数功能：统计除了简单单词外的单词
    map<string, size_t> word_count;
    // 定义
    set<string> exclude = {/*存储常见单词*/};
    string word;
    while(cin >> word)
    // 查找方法：.find
    // 如果找不到，则返回尾后迭代器
        if(exclude.find(word) == exclude.end())
            ++word_count[word];
    for(const auto &w : word_count){
        cout << w.first << " occurs " << w.second 
            << (w.second > 1 ? " times" : "time");
    }
}
```

#### 描述：vector和map的不同

* vector
  * 底层数据结构：数组、链表等
  * 每个元素都有特定的位置编号、按位置存取方便
  * 查找给定值效果不佳
* map
  * 底层数据结构：红黑树、哈希表
  * 高效实现搜索值的操作
  * 但是存储时空开销较大

#### 练习题

**练习：编写自己的单词统计程序**

```C++
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

// 有序头文件(包括可以重复和不可以重复)
#include <map>
#include <set>
// 无序头文件（包括可以重复和不可以重复）
#include <unordered_map>
#include <unordered_map>
```

```C++
void count_word_myself(string faddr){
    // 函数功能：自己的单词统计函数
    ifstream f(faddr);
    if(!f){
        cout << "打开输入文件失败！" << endl;
        exit(1);
    }
    map<string, size_t> word_count;
    string word;
    while(f >> word){
        ++word_count[word];
    }
    cout << "单词" << "：\t" << "出现次数" << endl;
    for(const auto &w : word_count){
        cout << w.first << "：\t" << w.second << endl;
    }
}
```

```C++
void count_word_exclude_upper_and_others(string faddr){
    ifstream f(faddr);
    if(!f){
        cout << "打开输入文件失败！" << endl;
        exit(1);
    }
    map<string, size_t> word_count;
    string word;
    char a;
    auto fuc = [](string &s){s.erase(s.find(',')); 
                                s.erase(s.find('.')); 
                                for_each(s.begin(), s.end(), [](char &a){a = tolower(a);});
                            };
    while(f >> word){
        fuc(word);
        ++word_count[word];
    }
    cout << "单词" << "：\t" << "出现次数" << endl;
    for(const auto &w : word_count){
        cout << w.first << "：\t" << w.second << endl;
    }
}
```


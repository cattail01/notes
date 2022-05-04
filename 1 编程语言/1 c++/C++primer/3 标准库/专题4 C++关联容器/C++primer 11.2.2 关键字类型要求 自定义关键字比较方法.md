[toc]

### 11.2.2 关键字类型的要求

* 对于有序关联容器（非哈希关联容器），关键字（key）必须能够被比较（默认为<，或者自己定义比较规则）

#### 有序容器的关键字类型要求

* 如果两个关键字的严格弱序是等价的（即按照排序方法为=），容器视为等价处理
* 如果关键字拥有<运算符的操作，则可以默认比较，否则需要自己定义比较规则

##### 严格弱序 性质（了解）

* 两个关键字不能同时小于等于对方（即不能相互等价）
* 小于等于具有传递性

#### 自定义关联容器的关键字比较方法

##### 自定义方法

* 让关键字类型支持<运算符
* 使用自定义比较函数重载（实际上是不使用默认参数）set或者map的类模板

##### 重载方法定义set

* 定义一个比较函数

```C++
bool isshorter(const string &str1, const string &str2){
    // 比较两个string类型的字符串，如果str1 < str2则返回true
    return str1.size() < str2.size();
}
```

* 用decltype（返回参数的类型）定义一个setI（decltype复习）
  * decltype的参数是可调用对象时，后面加上指针，生成指向该函数的指针类型，其实例化对象使用时会调用该函数
  * set实例化对象的初始化参数必须为要使用的排序函数（的指针/引用）

```C++
multiset<string, decltype(isshorter)*>
    string_string(isshorter);	// 默认指针
```

#### 练习

* 统计文件中单词出现的行

```C++
// 练习11.9 
// 函数功能：将单词格式化
// 参数：string &
// 返回值：string & 小写字母（大写转换成小写，去掉标点符号）
string &format_words(string &word){
    for(;;){
        auto find = find_if(word.begin(), word.end(), [](char chr){return ispunct(chr);});
        if(find == word.end())  break;
        word.erase(find);
    }
    for_each(word.begin(), word.end(), [](char &chr){chr = tolower(chr);});
    return word;
}
// 函数功能：将文件中的单词统计标号
// 参数：文件路径
// 返回值：单词到位置的映射 map<string, vector<int>>*
map<string, vector<int>> *
f_count_words(const string faddr){
    // 尝试打开文件
    // 文件打开模式复习
    auto in = ifstream(faddr/*, ios::in*/);
    if(!in){
        cout << "打开文件失败！" << endl;
        exit(1);
    }
    // 单词到行号的映射
    map<string, vector<int>> *word_lineno;
    string line;
    string word;
    int lineno = 0;
    // 统计每一行的单词※※
    while(getline(in, line)){       // getline从文件流中读取一行
        lineno ++;
        istringstream l_in(line);   // 字符串流
        while (l_in >> word){       // 将字符串流的单词输入程序（类似于cin）
            format_words(word);
            (*word_lineno)[word].push_back(lineno);
        }
    }
    return word_lineno;
}
// 函数功能：根据单词查找位置（单词到文件行号的映射）,并打印
void
find_and_print_addr(const string &word, map<string, vector<int>> *word_lineno){
    for(auto &i : (*(*word_lineno).find(word)).second){
        cout << i << " ";
    }
    cout << endl;
}
// 测试函数
void test_11_9(const char * addr){
    find_and_print_addr("word", f_count_words(addr));
}
```


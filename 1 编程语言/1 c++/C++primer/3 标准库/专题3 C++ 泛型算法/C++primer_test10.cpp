/*
 * C++primer 10 泛型算法
 * 案例与练习题测试
*/
#include <vector>
#include <list>
#include <string>
#include <iostream>
// 泛型算法常用头文件
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>

#include "../include/test10.h"

// using namespace std;

// 10.1 概述
void test_find_1(){
    // 对find()查找算法进行测试
    // find：
    // 参数：迭代器范围、要查找的值
    // 如果找到，则返回找到的迭代器
    // 如果找不到，则返回尾后迭代器
    vector<int> vec = {1, 2, 3, 4, 5};
    int val1 = 2;
    int val2 = 6;
    auto result1 = find(vec.begin(), vec.end(), val1);
    auto result2 = find(vec.begin(), vec.end(), val2);

    cout << "the value" << val1 << (result1 == vec.end() ? " is not present" : " is present") << endl;
    cout << "the value" << val2 << (result2 == vec.end() ? " is not present" : " is present") << endl;
}

// 练习：10.1 count：统计迭代器范围中出现指定值的数量
void test_count_1(){
    vector<int> vec = {2,0,1,9,0,2,0,4,4,2,2,1};
    int val1 = 2;
    int val2 = 3;
    auto result1 = count(vec.begin(), vec.end(), val1);
    auto result2 = count(vec.begin(), vec.end(), val2);

    cout << val1 << " 在序列中的个数为：" << result1 << endl;
    cout << val2 << " 在序列中的个数为：" << result2 << endl;
}
// 练习：10.2 count：统计string中出现字符的个数
void test_count_2(){
    string str = "cattail";
    char a = 't';
    cout << "t在cattail中的个数为：" << count(str.begin(), str.end(), a) << endl;
}

// 10.2.1 只读算法
void test_accumulate_1(){
    // numeric header
    // accumulate:
    // 功能：对范围内的数进行求和，并与第三个参数累加
    // 返回：范围内和基础数值的和
    // 注意：第三个参数的特点：其类型必须能够识别+=符号
    vector<int> vec = {1, 2, 3, 4, 5};
    int sum = accumulate(vec.begin(), vec.end(), 0);
    cout << "1 到 5 的和为：" << sum << endl;
    string str = "cattail";
    // 不能使用，因为char*类型字符串不支持+=自增长操作
    // string result = accumulate(str.begin(), str.end(), "");
    // 但是string支持+=操作，所以可以写成：
    string result = accumulate(str.begin(), str.end(), string(""));
    cout << result << endl;
}

void test_equal_1(){
    // equal:
    // 功能：用于确定两个容器中的内容是否相同
    // 特点：容器类型可以不相同，第二个容器至少比第一个大
    // 参数：第一个容器的迭代器范围；第二个容器的开始比较位置
    // 返回值：true 或 false
    string a = "cat";
    string b = "cattail";
    cout << a << "和" << b << "的比较是否相同？" 
        << (equal(a.begin(), a.end(), b.begin())?
        "相同":"不相同") << endl;
}

// 练习10.4
void test_accumulate_2(){
    // 测试：accumulate第三个参数为小范围类型时，返回值能否为大范围类型
    // 测试结果：不能
    vector<double> vec = {1.1, 2, 3, 4, 5};
    double result = accumulate(vec.cbegin(), vec.cend(), 0);
    cout << result << endl;
}

void test_fill_1(){
    // fill
    // 功能：将范围内的元素的值修改为第三个元素的值
    // 参数：迭代器范围、值
    vector<int> *vec = new vector<int>(10);

    // 将迭代器的全部变成0；
    fill(vec->begin(), vec->end(), 0);
    // 将迭代器的前半部分变成10；
    fill(vec->begin(), vec->begin() + vec->size() / 2, 10);

    for(auto i : *vec){
        cout << i << " ";
    }
    cout << endl;
}

void test_fill_n_1(){
    // fill_n
    // 功能：将范围内的元素的值修改为第三个元素的值
    // 参数：迭代器、改变的数量、值
    // 注意：要确保容器从第一个参数开始有第二个参数的数量的元素
    vector<int> *vec = new vector<int>(10);

    // 将迭代器的全部变成0；
    fill_n(vec->begin(), 10, 0);
    // 将迭代器的前半部分变成10；
    fill_n(vec->begin(), 5, 10);

    for(auto i : *vec){
        cout << i << " ";
    }
    cout << endl;
    delete vec;
}

void test_back_inserter_1(){
    // iterator header
    // back_inserter()
    // 功能：特殊的函数，返回一个尾插迭代器
    // 参数：容器的引用类型
    // 返回：返回一个插入（inserter）迭代器，
    // 向该迭代器赋值会调用容器的push_back方法，并自动向后移动一位
    // 测试：将尾插迭代器与修改迭代器(fill_n)连用，使其能够插入预设的值
    vector<int> vec;
    // 使用fill_n向vec的后面插入10个0；
    fill_n(back_inserter(vec), 10, 0);
    for(auto i : vec){
        cout << i << " ";
    }
}

void test_copy_1(){
    // copy
    // 功能：拷贝前面的范围到后面的序列内
    // 参数：迭代器范围、要拷贝位置的开始迭代器
    // 返回值：返回一个迭代器
    vector<double> vec = {1.1, 2, 3, 4, 5};
    vector<double> *vec_2 = new vector<double>((int)vec.size() + 1);
    auto result = copy(vec.begin(), vec.end(), vec_2->begin());
    vec_2->push_back(12);
    for(auto i : *vec_2){
        cout << i << " ";
    }
    cout << endl << *result << endl;
}

void test_replace_copy_1(){
    // replace
    // 功能：替换容器中的元素
    // 参数：迭代器范围、被替换的元素、新元素
    // 返回值：void
    // replace_copy
    // 功能：replace的copy版本（很多算法都有copy版本）
    // 参数：第三个新增了要拷贝到的开始位置
    const vector<int> vec = {1, 2, 3, 4, 5};
    vector<int> *vec_copy = new vector<int>(10);
    replace_copy(vec.begin(), vec.end(), vec_copy->begin(), 1, 0);
    for(auto i : *vec_copy){
        cout << i << " ";
    }cout << endl;
}

void test_sort_unique_1(){
    // sort
    // 功能：将范围内的元素排序
    // 参数：迭代器范围
    // unique
    // 功能：
    // 测试：将字符排序，并删除所有相同项目
    vector<string>vec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    cout << "排序后的结果：" << ends;
    sort(vec.begin(), vec.end());
    for(auto i : vec)   cout << i << " ";
    cout << endl;
    cout << "将相同的元素移动到后面：" << ends;
    auto end = unique(vec.begin(), vec.end());
    for(auto i : vec)   cout << i << " ";
    cout << endl;
    cout << "容器中实际容量" << "\t" << vec.size() << "\t";
    vec.erase(end, vec.end());
    cout << "删除后容器中实际容量" << "\t" << vec.size() << "\t";
    cout << endl;
}

template<typename T>
bool is_longer(const T &num1, const T &num2){
    return (num1 > num2);
}

void test_sort_2(){
    // 测试：接受谓词的sort函数（是一个重载版本）
    vector<int> vec = {1,2,3,4,5};
    sort(vec.begin(), vec.end(), is_longer<int>);
    for(auto i : vec)   cout << i << " ";
    cout << endl;
}

void test_stable_sort_1(){
    // stable_sort
    // 功能：稳定的排序方法
    // 参数、返回值：类似与sort函数
    // 测试：接受谓词的stable_sort函数（是一个重载版本）
    vector<int> vec = {1,2,3,4,5};
    stable_sort(vec.begin(), vec.end(), is_longer<int>);
    for(auto i : vec)   cout << i << " ";
    cout << endl;
}

void test_find_if_1(){
    // find_if
    // 功能：返回范围内第一个符合最后一个参数条件的迭代器
    // 参数：迭代器范围，可调用对象
    // 返回：目标的迭代器
    vector<int> vec = {1, 2, 3, 4, 5};
    auto addr = find_if(vec.begin(), vec.end(), [](const int &a){return a > 3;});
    cout << *addr << endl;
}

void test_lambda_1(){
    // lambda
    // 格式：[捕获列表](参数列表)->返回类型{函数体}
    // 可删：参数列表，返回类型
    auto f = []{return 42;};
    cout << f() << endl;
}

void test_lambda_2(){
    // 测试：向lambda传参
    // 功能：使用lambda代替is_longer函数功能
    vector<int> vec = {1,2,3,4,5};
    stable_sort(vec.begin(), vec.end(), [](const int &a, const int &b){return a > b;});
    for(auto i : vec)   cout << i << " ";
    cout << endl;
}

void test_lambda_3(){
    // 测试：使用lambda捕获列表
    vector<int> vec = {1, 2, 3, 4, 5};
    int num = 3;
    auto addr = find_if(vec.begin(), vec.end(), [num](const int &a){return a > num;});
    cout << *addr << endl;
}

void test_for_each(){
    // for_each
    // 功能：对范围内的元素执行指定操作
    // 参数：迭代器范围，可调用对象
    // 返回值：第三个参数
    vector<int> vec = {1, 2, 3, 4, 5};
    for_each(vec.begin(), vec.end(), [](const int &i){cout << i << " "; });
}

void biggies_1(vector<string> &words, vector<string>::size_type sz){
    // 输出满足长度的单词
    // 字典排序，删除重复单词
    sort(words.begin(), words.end());
    auto end = unique(words.begin(), words.end());
    words.erase(end, words.end());
    // 长度排序，长度相同的单词保持顺序
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b){return a.size() < b.size();});
    // 获取迭代器，指向第一个满足size() >= sz的元素
    auto first = find_if(words.begin(), words.end(), [sz](const string &a){return a.size() >= sz;});
    // 计算满足条件的数目
    auto count = words.end() - first;
    cout << count << " word" << (count > 1 ? "s" : "") << " of length " << sz << " or longer" << endl;
    // 打印符合条件的单词
    for_each(words.begin(), words.end(), [](const string &a){cout << a << " ";});
    cout << endl;
}

void test_lambda_4(){
    // 对lambda值捕获进行测试
    // 测试其拷贝时间（创建 or 调用）
    size_t v1 = 42;
    auto f = [v1]{return v1;};
    v1 = 0;
    cout << f();
}

void test_lambda_5(){
    // 对lambda引用捕获测试
    // 测试其捕获的对象
    size_t v1 = 42;
    auto f = [&v1]{return v1;};
    v1 = 0;
    cout << f();
}

/*10.2.2节练习*/
// 10.7
void test_gaicuo_10_7_1(){
    /*测试数据：1 2 3 4 5 6*/
    vector<int> vec; list<int>list; int i;
    while(cin >> i){
        list.push_back(i);
    }
    // copy(list.begin(), list.end(), vec.begin());
    /*cc1plus.exe: out of memory allocating 65536 bytes*/
    copy(list.cbegin(), list.cend(), back_inserter(vec));
    /*1 2 3 4 5 6*/
    for_each(vec.begin(), vec.end(), [](const int &a){cout << a << " ";});
}

/*10.3.1 节练习*/
// 10.13 partition算法
void test_partition_1(){
    // partition
    // 功能：将符合谓词的元素前置
    // 参数：迭代器范围，谓词
    // 返回值：迭代器，指向最后一个使谓词为true之后的谓词
    vector<string> words = {"i", "am", "a", "good", "people"};
    auto end = partition(words.begin(), words.end(), [](const string &str){return str.size() >= 4;});
    words.erase(end, words.end());
    for_each(words.begin(), words.end(), [](const string &str){cout << str << " ";});
}

void test_lambda_6(){
    // 测试：lambda表达式的隐式捕获
    int v1 = 42;
    // 隐式值捕获
    auto f1 = [=](){return v1;};
    // 隐式引用捕获
    auto f2 = [&](){return v1;};
    v1 = 0;
    cout << "f1="<< f1() << endl << "f2=" << f2() << endl;
}

void test_lambda_7(){
    // 测试：lambda表达式的混合捕获
    int v1 = 1, v2 = 2;
    auto f1 = [=, &v2](){cout << v1 << " " << v2 << endl;};
    auto f2 = [&, v2](){cout << v1 << " " << v2 << endl;};
    f1();
    f2();
    v1 = v2 = 0;
    f1();
    f2();
}

void test_lambda_mutable_8(){
    // 测试：可变的值捕获：mutable
    int v1 = 42;
    auto f1 = [v1]()mutable{cout << ++v1 << endl;};
    auto f2 = [&](){cout << ++v1 << endl;};
    v1 = 0;
    cout << v1 << endl;
    f1();
    f2();
    cout << v1 << endl;
}

void test_lambda_9(){
    // 测试：当lambda推断的返回类型错误时指定返回类型
    // 注意：此处必须指定返回值（无法自动推断）
    auto f = [](int i)->int{if(i > 0) return i; else return -i;};
    cout << f(-1) << " " << f(2) << endl;
}

/*10.3.3 节练习*/
// 10.20
void test_count_if_1(){
    // count_if
    // 功能：按需求计数
    // 参数：迭代器范围，谓词
    // 返回值：整数，表示多少次谓词为true
    vector<int> vec = {1, 2, 3, 4, 5, 6};
    int count = count_if(vec.begin(), vec.end(), [](const int &a){return !(a % 2);});
    cout << count << endl;
}

/*10.3.4 参数绑定*/
void test_bind_1(){
    // bind
    // 格式：auto newCallable = bind(callable, arg_list);
    // 功能：实现传入参数的缩小与参数的捕获
    // 原理：当调用newCallable时，调用callable，并传递给它arg_list中的参数
    // arg_list中的参数：正常参数，_n占位符，表示传递给newCallable的参数
    // 测试：计算1 + 2的值
    using namespace std::placeholders;
    auto f = [](const int &c1,const int &c2){return c1 + c2;};
    auto f_b = bind(f, _1, 2);
    cout << f_b(1);
}

void test_bind_2(){
    // 测试：使用bind颠倒传参，is_longer由小到大排序
    using namespace std::placeholders;
    vector<int> vec = {1, 2, 3, 4, 5};
    sort(vec.begin(), vec.end(), is_longer<int>);
    for_each(vec.begin(), vec.end(), [](const int &i){cout << i << " ";});
    cout << endl;
    sort(vec.begin(), vec.end(), bind(is_longer<int>, _2, _1));
    for_each(vec.begin(), vec.end(), [](const int &i){cout << i << " ";});
    cout << endl;
}

void test_ref_bind_3(){
    // ref：返回参数的引用对象
    // cref：返回参数的const引用对象
    auto f = [](int &a){++a;};
    int a = 0;
    auto f_b = bind(f, ref(a));
    f_b();
    cout << a << endl;
}

/*10.4*/
void test_inserters_1(){
    // 探究：inserter的操作原理
    vector<int> old {1, 2, 3, 4, 5};
    list<int> list1, list2;
    copy(old.begin(), old.end(), front_inserter(list1));
    copy(old.begin(), old.end(), inserter(list2, list2.begin()));
    auto f = [](const int &a){cout << a << " ";};
    for_each(list1.begin(), list1.end(), f);
    cout << endl;
    for_each(list2.begin(), list2.end(), f);
}

void test_istream_iterator_1(){
    // 从cin读取int型字符
    istream_iterator<int> in_iter(cin);
    // 设置尾后迭代器
    istream_iterator<int> eof;
    vector<int> vec;
    // 当还能读取时，放入容器中
    while (in_iter != eof){
        vec.push_back(*in_iter ++);
    }
    for_each(vec.begin(), vec.end(), [](const int &a){cout << a << " ";});
}

void test_istream_iterator_2(){
    // 上面的程序的重写版本
    istream_iterator<int> in_ter(cin), eof;
    vector<int> vec(in_ter, eof);
    for_each(vec.begin(), vec.end(), [](const int &a){cout << a << " ";});
}

void test_istream_iterator_algorithm_1(){
    // 测试：算法和流迭代器同时使用
    istream_iterator<int> in(cin), eof;
    cout << accumulate(in, eof, 0);
}

void test_ostream_iterator_1(){
    // 测试：输出流迭代器功能
    vector<int> vec = {1, 2, 3, 4, 5};
    // 定义迭代器，并设置间隔输出
    ostream_iterator<int> out(cout, " ");
    for(auto &a : vec){
        *out++ = a;
    }
    cout << endl;
}

void test_riterator_1(){
    // 测试：反向迭代器
    vector<int> vec{1, 2, 3, 4, 5};
    for(auto iter = vec.crbegin(); iter != vec.crend(); iter++){
        cout << *iter << " ";   // 反向输出
    }
    auto riter = vec.crbegin();
    auto iter = riter.base();
    cout << endl;
}


/*
 * 第11章 关联容器
 * 
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
#include <cstdlib>

// 有序头文件(包括可以重复和不可以重复)
#include <map>
#include <set>
// 无序头文件（包括可以重复和不可以重复）
#include <unordered_map>
#include <unordered_map>

#include "../include/test11.h"
using namespace std;

void count_words_1(){
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

void difference_between_multi_and_not(){
    // 测试：multi版本和普通版本的区别
    vector<int> vec = {1, 1, 2, 2};
    set<int> iset(vec.begin(), vec.end());
    multiset<int> miset(vec.begin(), vec.end());

    cout << vec.size() << endl;
    cout << iset.size() << endl;
    cout << miset.size() << endl;
}

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
f_count_words(const string &faddr){
    // 尝试打开文件
    // 文件打开模式复习
    auto in = ifstream(faddr/*, ios::in*/);
    if(!in){
        cout << "打开文件失败！" << endl;
        exit(1);
    }
    // 单词到行号的映射
    map<string, vector<int>> *word_lineno = new map<string, vector<int>>;
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

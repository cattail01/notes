[toc]

### 10.2.3 重拍元素容器的算法

#### sort 排序 unique 整合 排序元素并删除相同的元素

```C++
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
/*
	排序后的结果：fox jumps over quick red red slow the the turtle 
	将相同的元素移动到后面：fox jumps over quick red slow the turtle the
	容器中实际容量  10      删除后容器中实际容量    8
*/
```


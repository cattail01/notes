[toc]

### 11.3 关联容器操作

#### 关联容器额外的类型别名

```C++
map<value_type>
    value_type: pair<const key_type, mapped_type>
```

##### 使用方法

```C++
map<string, int>::value_type;	// pair<string, int>
map<string, int>::key_type;		// const string
map<string, int>::mapped_type;	// int
set<string>::key_type == value_type;	// true	// const string 
// set<string>::mapped_type;
```


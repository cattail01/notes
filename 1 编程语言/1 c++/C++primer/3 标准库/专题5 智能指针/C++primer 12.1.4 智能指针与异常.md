[toc]

### 12.1.3 智能指针与异常

#### 引入

* 自己new出来的对象，如果在delete之前thorw出异常，则永远不会自动消除
* 可以使用shared_ptr避免该类现象

#### 智能指针和哑类

* 未用new定义的指针，有些需要手动释放
* 不能用普通的shared_ptr管理（不能用delete释放）

#### 使用自己的释放操作（shared<obj*, deleter>）

* 功能：对于不能使用delete的资源自动管理，可以自己定义释放的方法

```C++
// class distination;	// 表示连接的东西
// class connection;	// 表示连接的信息
connection connect(distination*);	// fuc，建立连接
void disconnect(distination);	// fuc, 销毁连接
void fuc(){
    connection c = connect(&d);
    shared_ptr<connection> p(&c, disconnect);
}
```

#### 正确使用智能指针

* 不能将一个地址初始化或reset给两个智能指针
* 不能同时将普通指针和智能指针指向同一位置
* 如果shared_ptr管理的不是new出来的对象，记得给一个deleter


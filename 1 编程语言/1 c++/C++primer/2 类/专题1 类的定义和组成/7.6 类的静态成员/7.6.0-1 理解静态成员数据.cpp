// 对构造了多少次对象进行统计
// 菜鸟教程

#include <iostream>
 
using namespace std;

class Box
{
   public:
      static int objectCount;
      // 构造函数定义
      Box(double l=2.0, double b=2.0, double h=2.0)
      {
		 // 创建对象时打印
         cout <<"Constructor called." << endl;
         // 每次创建对象时统计，增加 1
         objectCount++;
      }
};
 
// 对类属性进行重新声明，并初始化
int Box::objectCount = 0;
 
int main(void)
{
   Box Box1(3.3, 1.2, 1.5);    // 声明 box1
   Box Box2(8.5, 6.0, 2.0);    // 声明 box2
 
   // 输出创建对象的总数
   cout << "Total objects: " << Box::objectCount << endl;
 
   return 0;
}

/* 结果
Constructor called.
Constructor called.
Total objects: 2
*/

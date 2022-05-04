/*
 * 给你两个整数 a 和 b ，不使用 运算符 + 和 - ​​​​​​​，计算并返回两整数之和。
*/

class Solution {
public:
    int getSum(int a, int b) {
        // 可以使用全加器原理
        if(b == 0)    return a;
        int c =( a ^ b );
        int d = (unsigned)(a & b) <<1;
        
        return getSum(c, d);
    }
};

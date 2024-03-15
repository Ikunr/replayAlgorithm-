/* 面试题16：数值的整数次方
题目：实现函数double Power(double base, int exponent)，求base的exponent
次方。不得使用库函数，同时不需要考虑大数问题。*/

#include <iostream>

double power(double base, int exponent)
{
    if (exponent == 0)
    {
        return 1;
    }
    if (exponent == 1)
    {
        return base;
    }
    /* 递归自己  16 拆开为 8 和 8   在将8拆开为 4 和 4 一次类推 */
    double result = power(base, exponent >> 1);
    result *= result;
    /* 判断当前为奇数还是偶数 */
    if (exponent & 0x1 == 1)
    {
        result *= base;
    }

    return result;

}



int main()
{
    double ret = power(-1, 6);
    std::cout<<"ret : "<<ret<<std::endl;
}

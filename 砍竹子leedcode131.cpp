/* 现需要将一根长为正整数 bamboo_len 的竹子砍为若干段，
    每段长度均为正整数。请返回每段竹子长度的最大乘积是多少。

示例 ： 输入: bamboo_len = 12
        输出: 81
*/
#include <iostream>

// using namespace std;

int cuttingBamboo(int bamboo_len)
{
    if (bamboo_len < 2)
    {
        return 0;
    }
    if (bamboo_len == 2)
    {
        return 1;
    }
    if (bamboo_len == 3)
    {
        return 2;
    }
    /* 多一个是因为数组下标从 0~bamboo_len */
    int * product = new int[bamboo_len + 1];
    /* 正确初始化 防止出现未初始化的现象 */
    product[0] = 0;
    product[1] = 1;
    product[2] = 2;
    product[3] = 3;

    int max = 0;
    for (int idx = 4; idx <= bamboo_len; idx++)
    {
        max = 0;
        for (int jdx = 1; jdx <= idx / 2; jdx++)
        {
            int maxnum = product[jdx] * product[idx - jdx];
            if (max < maxnum)
            {
                max = maxnum;
            }
            /* 保证每次更新最优解在 idx的位置 */
            product[idx] = max;
        }
    }
    /* 最后在末尾的位置 */ 
    max = product[bamboo_len];
    delete[] product;
    return max;

}


int main()
{
    int num = 12;
    int ret = cuttingBamboo(num);

    std::cout<<"ret : "<<ret<<std::endl;
}
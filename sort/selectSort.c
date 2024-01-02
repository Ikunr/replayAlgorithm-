#include <stdio.h>
#include <stdlib.h>
/* 算法思想 1、 从pos位置的后面位置找到最小的元素                               /
           2、 将第一步得到的数和POS位置的值比较如果小于Pos 就交换数据           /
           3、 POS位置向后移                                                  /
*/

int selectSort(int *array, int len)
{
    for (int idx = 0; idx < len - 1; idx++)
    {
        /* 将0 的位置定义为最小的下标 让之后的元素和最小的值进行比较 找到更小的值进行交换 */
        int mix_idx = idx;
        for (int jdx = idx + 1; jdx < len; jdx++)
        {
            if (array[jdx] < array[mix_idx])
            {
                mix_idx = jdx;
            }
        }
        int temp = array[mix_idx];
        array[mix_idx] = array[idx];
        array[idx] = temp; 
    }
}

int selectSort1(int *array, int len)
{
    int pos = 0;

    while(pos < len - 1)
    {
        int minNum = pos;
        for (int idx = pos + 1; idx < len; idx++)
        {
            if (array[idx] < array[minNum])
            {
                minNum = idx;
            }
        }
        int temp = array[minNum];
        array[minNum] = array[pos];
        array[pos] = temp;
        pos++;
    }
}


int main()
{
    int array[] = {1, 3, 5, 4, 20, 80, 60, 1};

    int len = sizeof(array) / sizeof(array[0]);

    selectSort(array, len);

    for (int idx = 0; idx < len; idx++)
    {
        printf(" %d", array[idx]);
    }

    printf("\n");
}
#include <stdio.h>
#include <stdlib.h>

/* 将未排序的元素和已排序的元素进行比较 如果 */
/* 算法思想 1、                                /
           2、 将第一步得到的数和POS位置的值比较如果小于Pos 就交换数据           /
           3、 POS位置向后移                                                  /
*/

int insertSort(int *array, int len)
{
    int currentVal = 0;
    int preIdx = 0;

    for(int idx = 1; idx < len; idx++)
    {
        currentVal = array[idx];
        preIdx = idx - 1;

        while(preIdx >= 0 && currentVal < array[preIdx])
        {
            array[preIdx + 1] = array[preIdx]; 
            preIdx--;
        }
        array[preIdx + 1] = currentVal;
        
    }
}


int main()
{
    int array[] = {1, 3, 5, 4, 20, 80, 60, 1};

    int len = sizeof(array) / sizeof(array[0]);

    insertSort(array, len);

    for (int idx = 0; idx < len; idx++)
    {
        printf(" %d", array[idx]);
    }

    printf("\n");
}











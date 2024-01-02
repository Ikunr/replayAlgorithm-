#include <stdio.h>

#define BUFFER_SIZE 6

/* 交换俩个变量的值 */
int swap(int *val1, int *val2)
{
    int ret = 0;
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;

    return ret;
}

/* 数组做参数会自动弱化成指针 */
int printArray(int *array, int arraySize)
{
    for (int idx = 0; idx < arraySize; idx++)
    {
        printf("array[%d] = %d\n", idx, array[idx]);
    }
}

/* 冒泡排序 */
void buffSort(int *array, int length)
{
    for (int end = length; end > 0;  end--)
    {
        for (int begin = 1; begin < end; begin++)
        {
            /* 如果当前值比前一个数小 就交换 */
            if (array[begin] < array[begin - 1])
            {
                swap(&array[begin], &array[begin - 1]);
            }
        }
    }
}

int main()
{
    int array[BUFFER_SIZE] = {11, 36, 24, 107, 65, 23};

    int length = sizeof  (array) / sizeof(array[0]);

    buffSort(array, length);
    printArray(array, length);

    return 0;
}
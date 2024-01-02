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
void buffSort1(int *array, int length)
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


/* 冒泡排序 */
/* 优化1 */
void buffSort2(int *array, int length)
{
    int sorted; 
    for (int end = length; end > 0;  end--)
    {
        /* 已经排好序的标志 */
        sorted = 1;
        for (int begin = 1; begin < end; begin++)
        {
            /* 如果当前值比前一个数小 就交换 */
            if (array[begin] < array[begin - 1])
            {
                swap(&array[begin], &array[begin - 1]);
                /* 数据是没有排好序的 */
                sorted = 0;
            }
        }
        if (sorted == 1)
        {
            break;
        }
    }
}

/* 优化2 */
void buffSort3(int *array, int length)
{
    int sortedIndex = 0;
    
    for (int end = length; end > 0;  end--)
    {
        /* 已经排好序的索引 */
        sortedIndex = 1;
        for (int begin = 1; begin < end; begin++)
        {
            /* 如果当前值比前一个数小 就交换 */
            if (array[begin] < array[begin - 1])
            {
                swap(&array[begin], &array[begin - 1]);
                /* 更新索引的位置 */
                sortedIndex = begin;
            }
        }
        /* 更新。 */
        end = sortedIndex;
    }
}

int main()
{
    int array[BUFFER_SIZE] = {11, 36, 24, 107, 65, 23};

    int length = sizeof  (array) / sizeof(array[0]);

    buffSort(array, length);
    buffSort2(array, length);
    buffSort3(array, length);

    printArray(array, length);

    return 0;
}
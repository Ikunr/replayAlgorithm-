#include <stdio.h>
#define BUFFER_SIZE 6 

void insertSort(int *array, int length)
{
    int currentVal = 0;
    int preIndex = 0;

    for (int idx = 1; idx < length; idx++)
    {
        currentVal = array[idx];
        preIndex = idx - 1;

        while(preIndex > 0 && currentVal < array[preIndex])
        {
            array[preIndex + 1] = array[preIndex]; 
            preIndex--;
        }
         array[preIndex + 1] = currentVal;
    }

}

/* 数组做参数会自动弱化成指针 */
int printArray(int *array, int arraySize)
{
    int ret = 0;
    for (int idx = 0; idx < arraySize; idx++)
    {
        printf("array[%d] = %d\n", idx, array[idx]);
    }
    return ret;
}

int main()
{
    int array[BUFFER_SIZE] = {11, 36, 24, 107, 65, 23};

    int length = sizeof  (array) / sizeof(array[0]);

    insertSort(array, length);

    printArray(array, length);

}
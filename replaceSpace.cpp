#include <cstdio>
#include <cstring>
#include <iostream>

#define BUFFER_SIZE 50

/* 面试题5：替换空格
   题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
   则输出“We%20are%20happy.” */

/*length 为字符数组str的总容量，大于或等于字符串str的实际长度*/
void ReplaceBlank(char str[], int length)
{
    std::cout<<length<<std::endl;
    if(str == nullptr && length <= 0)
        return;

    /*originalLength 为字符串str的实际长度*/
    /* numberOfBlank 为字符串空格的个数 */
    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    while(str[i] != '\0')
    {
        ++ originalLength;

        if(str[i] == ' ')
            ++ numberOfBlank;

        ++ i;
    }

    /*newLength 为把空格替换成'%20'之后的长度*/
    int newLength = originalLength + numberOfBlank * 2;
    if(newLength > length)
        return;

    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        if(str[indexOfOriginal] == ' ')
        {
            str[indexOfNew --] = '0';
            str[indexOfNew --] = '2';
            str[indexOfNew --] = '%';
        }
        else
        {
            str[indexOfNew --] = str[indexOfOriginal];
        }

        -- indexOfOriginal;
    }
    
}


int main()
{
    /* str[]  str[50] 区别 */
    /* 原来的数组可能没有足够的空间来存储修改后的字符串，因为数组的大小已经被固定，不能动态扩展。 */
    char str[BUFFER_SIZE] = "we are happy.";
    ReplaceBlank(str, sizeof(str) / sizeof(str[0]));

    std::cout<<str<<std::endl;
}
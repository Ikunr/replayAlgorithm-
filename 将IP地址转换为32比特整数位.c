/* 用C语言实现点分IP地址到32比特整数之间的转换例如输入字符串"10.10.101”，输出168430081。非法p地址比如"1234 1test 
返回 0 参考信息IP地址是一个32位的三进制数，通常被分割为4个8位二进制数”(也就是4个字节)。IP地址通常用 “点分进制” 表示成(a.b.c.d)的形式，
其中，a,b,c,a都是0255之间的十进制整数。
例:点分十进IP地址(100.46):实际上是32位二进制数(01100100.00000100.0000101.00000110)，其16进制数(0x6404050) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* "10.10.10.1" */
int ip_to_int(const char* ip) 
{
    int result = 0;
    int part = 0;
    int shift = 24; // 初始偏移量设为24

    for (const char *p = ip; *p; ++p) 
    {
        if (*p == '.') 
        {
            result |= (part << shift);
            part = 0;
            shift -= 8;
        } 
        else if (*p >= '0' && *p <= '9') 
        {
            part = part * 10 + (*p - '0');
            if (part > 255) 
            {  // 检查每个部分是否在合法范围内
                printf("非法IP地址\n");
                return 0;
            }
        } 
        else 
        {
            printf("非法IP地址\n");
            return 0;
        }
    }
    result |= part;  // 处理最后一部分
    return result;
}

int main() 
{
    const char* ip_address = "10.10.10.1";
    int result = ip_to_int(ip_address);
    printf("%u\n", result);
    return 0;
}


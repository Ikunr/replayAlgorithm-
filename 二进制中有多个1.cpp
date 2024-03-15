#include <iostream>


int biteNums(int n)
{
    int count = 0;
    
    while(n)
    {
        count++;
        n = (n - 1) & n;
    }
    return count;
}

int main()
{
    int ret = biteNums(9);
    printf("ret : %d\n", ret);

}
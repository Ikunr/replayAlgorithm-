/* 在唱歌海选比赛中会有多位群众对选手进行打分分数范围为1-100000的整数，打分观众人数范围为1-100，
如果某个分数出现的次数超过一半，这个分数就是选手的分数。请你帮忙用C谦贾写一个高效的程序找出选手的得分，
如果没有分数满足要求则返回0。*/

#include <stdio.h>
#include <stdlib.h>


int majorityElement(int* nums, int numsSize) 
{
    int score = 0;
    int count = 0;

    for (int idx = 0; idx < numsSize; idx++)
    {
        if (nums[idx] == score)
        {
            count++;
        }
        else if (count == 0)
        {
            score = nums[idx];
            count = 1;
        }
        else
        {
            count--;
        }
    }

    if (count == 0)
    {
        return 0;
    }
    else
    {
        return score;
    }


}


int main()
{
    int num[7] = {90, 100, 90, 90, 96, 90, 95};

    int ret = majorityElement(num, sizeof(num) / sizeof(num[0]));
    // int ret = majorityElement(num, 8);
    printf("ret : %d\n", ret);

}
/* 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素 
示例 ： 输入：nums = [3,2,2,3], val = 3
        输出：2, nums = [2,2]。
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
#if 0
        int index = 0;
        for (int idx = 0; idx < nums.size(); idx++)
        {
            if (nums[idx] == val)
            {
                continue;
            }
            nums[index] = nums[idx];
            index++;
        }
        return index;
#else 
        int right = 0;
        int n = nums.size();
        for (int left = 0 ;left < n; left++)
        {
            if (nums[left] != val)
            {
                nums[right] = nums[left];
                right++;
            }
        }
    
#endif
    }
};


int main()
{
    Solution pStr;

    vector<int> my_vector = {3, 2, 2, 3};
    int val = 3;
    
    cout<<pStr.removeElement(my_vector, val)<<endl;

    for (auto &c : my_vector)
    {
        cout<<c;
    }
    printf("\n");

}
/*  给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
    如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
    请必须使用时间复杂度为 O(log n) 的算法。
*/


#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        int start = 0;
        int end = nums.size() - 1;
        
        while(start <= end)
        {
            int mid = (start + end) / 2;
            
            if (target > nums[mid])
            {
                start = mid + 1;
            }
            else if (target < nums[mid])
            {
                end = mid - 1;
            }
            else 
            {
                return mid;
            }    
        }
        return end + 1;
    }
};

int main()
{
    Solution pStr;
    vector<int> my_vector = {1,3,5,6};
    int ret = pStr.searchInsert(my_vector, 5);
    cout<<"ret : "<<ret<<endl;
    // my_vector.push_back();
}
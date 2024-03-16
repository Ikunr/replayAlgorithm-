/* 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
如果 needle 不是 haystack 的一部分，则返回  -1 。
输入：haystack = "sadbutsad", needle = "sad"
输出：0
解释："sad" 在下标 0 和 6 处匹配。
第一个匹配项的下标是 0 ，所以返回 0 
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        if (haystack.length() == 0 | needle.length() == 0)
        {
            return -1;
        }
        int jdx = 0;
        for (int idx = 0; idx < haystack.length(); idx++)
        {
            if (haystack.at(idx) == needle.at(jdx))
            {
                jdx++;
                if (jdx == needle.length())
                {
                    return idx - jdx +  1;
                }
            }
            else
            {
                idx = idx - jdx;
                jdx = 0;
            }
        
        }
        return -1;

    }
};

int main()
{
    Solution pStr;
    
    cout<<"最开始匹配下标的位置 : "<<pStr.strStr("leetcode", "leetc")<<endl;
}
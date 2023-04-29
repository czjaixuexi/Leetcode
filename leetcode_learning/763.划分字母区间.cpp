// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem763.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int index[26] = {0};
        for (int i = 0; i < s.length(); i++)
        {
            index[s[i] - 'a'] = i; //更新每个字母最后出现的位置
        }
        vector<int> res;
        int left = 0;
        int right = 0;
        for (int i = 0; i < s.size(); i++)
        {
            right = max(right, index[s[i] - 'a']); //找到字符出现的最右边界
            if (i == right)                        //到达当前字符串的最右边界
            {
                res.push_back(right - left + 1);
                left = i + 1; //更新左边界
            }
        }
        return res;
    }
};
// @lc code=end
"eccbbbbdec"
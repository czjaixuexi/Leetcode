// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_set>
#include "commoncppproblem128.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> set;
        int res = 0;
        for (auto &a : nums)
        {
            set.insert(a);
        }
        for (auto &a : nums)
        {
            //当该数字的前一个数不存在时，以该数字为起始点，开始计算连续字序列的长度
            if (set.count(a - 1) == 0)
            {
                int firstnum = a;
                int count = 1;
                //每个数字只会被遍历一次
                while (set.count(firstnum + 1))
                {
                    firstnum++;
                    count++;
                }
                res = max(res, count);
            }
        }
        return res;
    }
};
// @lc code=end

// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem494.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
// + 部分的总和为x，  则-部分的绝对值为sum-x，值为-(sum-x)
// x-(sum-x) = target
// x = (sum + target) /2
// 简化为装满容量为x的包，有几种方法
// dp[j] 表示装满容量为j的包，有几种方法
// dp[j] += dp[j-nums[i]]
// dp[0] =1; 
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum)
            return 0;
        if ((sum + target) % 2)
            return 0;
        int plus = (sum + target) / 2;
        vector<int> dp(plus + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = plus; j >= nums[i]; j--)
            {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[plus];
    }
};
// @lc code=end

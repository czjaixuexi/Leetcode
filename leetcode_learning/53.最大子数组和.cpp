// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem53.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
// dp[i] 表示前i项以nums[i]结尾的最大连续子数组和
// dp[i]= max(nums[i],dp[i-1]+nums[i])
// dp[0] = nums[0]
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {   
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            res = max(dp[i], res);
        }
        return res;
    }
};
// @lc code=end

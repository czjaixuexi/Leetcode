// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem198.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
// dp[i]表示前n间房屋能偷到的最高金额
// dp[i] = max(dp[i-2]+nums[i],dp[i-1])
// dp[0] = 0
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        vector<int> dp(nums.size() + 1, 0);
        dp[1] = nums[0];
        dp[2] = max(nums[0], nums[1]);
        for (int i = 3; i <= nums.size(); i++)
        {
            dp[i] = max(dp[i - 2] + nums[i-1], dp[i - 1]);
        }
        return dp[nums.size()];
    }
};
// @lc code=end

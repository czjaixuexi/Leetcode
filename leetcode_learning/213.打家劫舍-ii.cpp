// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem213.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
// dp[i]表示前i间房屋能偷到的最高金额
// dp[i] = max(dp[i-2]+nums[i],dp[i-1])
// dp[0] = 0
//分两种情况：1.不包含首房间 2.不包含尾房间

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int res1 = helper(nums, 1, nums.size() - 1); //不包含首房间
        int res2 = helper(nums, 0, nums.size() - 2); //不包尾房间
        return max(res1, res2);
    }
    int helper(vector<int> &nums, int start, int end)
    {
        if (start == end)
            return nums[start];
        vector<int> dp(nums.size());
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[end];
    }
};
// @lc code=end

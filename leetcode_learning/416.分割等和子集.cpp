// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem416.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
// dp[j] 表示上限为j时，nums的子集可以得出的最大和
// dp[j] = max(dp[j],dp[j-nums[i]+nums[i]])

//求是否含有子集的和为该集合总和的1/2
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        //总和为奇数，无法取得，直接返回错误
        if (sum % 2)
            return false;
        int target = sum / 2;
        vector<int> dp(100001, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = target; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (dp[target] == target)
            return true;
        return false;
    }
};
// @lc code=end

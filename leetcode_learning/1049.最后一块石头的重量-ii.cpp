// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1049.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start

//将石头分为质量相似的两堆，其中一堆为sum1 = sum/2
// dp[j]表示背包容量为j时候，所能容纳的最多的石头质量
// dp[j] = max(dp[j],dp[j-stones[i]]+stones[i])
class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int sum = 0;
        for (auto a : stones)
        {
            sum += a;
        }
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        // 0/1背包遍历
        for (int i = 0; i < stones.size(); i++)
        {
            for (int j = target; j >= stones[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - dp[target] - dp[target];
    }
};
// @lc code=end

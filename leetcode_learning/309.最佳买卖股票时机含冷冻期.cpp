// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem309.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
// dp[i][0] 表示第i天，持有股票的最大收益
// dp[i][1] 表示第i天，未持有（非冷冻期）的最大收益
// dp[i][2] 表示第i天，未持有（冷冻期）的最大收益
// dp[i][0] = max(dp[i-1][0],dp[i-1][1]-prices[i])
// dp[i][1] = max(dp[i-1][1],dp[i-1][2])
// dp[i][2] = dp[i-1][0] + prices[i]
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 1)
            return 0;
        vector<vector<int>> dp(n, vector<int>(3));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]);
            dp[i][2] = dp[i - 1][0] + prices[i];
        }
        return max(dp[n - 1][1], dp[n - 1][2]);
    }
};
// @lc code=end

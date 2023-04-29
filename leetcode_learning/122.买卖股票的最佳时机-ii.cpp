// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem122.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
// dp[i][0]表示第i天不持有股票时候的最大利润,dp[i][1]表示第i天持有股票时的最大利润
// dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i])  (两种情况:i-1天不持有；i-1天持有，i天卖出)取最大值
// dp[i][1] = max(dp[i-1][1],dp[i-1][0]-prices[i]) (两种情况:i-1持有；i-1天不持有，i天买入)取最大值
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), {0, 0});
        dp[0][1] = -prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[prices.size() - 1][0];
    }
};
// @lc code=end

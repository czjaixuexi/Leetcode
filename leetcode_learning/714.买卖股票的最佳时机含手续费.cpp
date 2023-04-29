// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem714.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
// dp[i][0] 表示第i天未持有股票(卖出) 状态的最大收益
// dp[i][1] 表示第i天持有股票（买入）状态的最大收益
// dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]-fee)
// dp[i][1] = max(dp[i-1][1],dp[i-1][0]-prices[i])
// dp[0][0] = 0;
// dp[0][1] = -prices[0];
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        if (prices.size() == 1)
            return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[prices.size() - 1][0];
    }
};
// @lc code=end

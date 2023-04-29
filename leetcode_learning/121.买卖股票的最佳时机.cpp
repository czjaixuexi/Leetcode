// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem121.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
// dp[i]表示第i天的最大利润
// dp[i] = max(dp[i-1],prices[i]−minprice)
// dp[0] = dp[1] = 0
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minprice = prices[0];
        vector<int> dp(prices.size(), 0);
        for (int i = 1; i < prices.size(); i++)
        {
            minprice = min(prices[i], minprice);
            dp[i] = max(dp[i - 1], prices[i] - minprice);
        }
        return dp[prices.size() - 1];
    }
};
// @lc code=end

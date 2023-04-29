// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem123.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
// dp[i][j][0] 表示第 x 天，  j交易次数， 未持有股票的最大利润
// dp[i][j][1] 表示第 x 天，  j交易次数， 持有的股票最大利润
// dp[i][j][0] = max(dp[i-1][j][0],dp[i-1][j][1]+prices[i])
// dp[i][j][1] = max(dp[i-1][j-1][0]-prices[i],dp[i-1][j][1])
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int dp[n][3][2];
        memset(dp, 0, sizeof dp);
        //初始化第一天
        dp[0][0][0] = 0;
        // 交易 0 次， 持有股票，不可能存在
        dp[0][0][1] = -100001;
        // 交易 1 次， 没有持有股票， 不可能存在
        dp[0][1][0] = -100001;
        // 交易 1 次， 持有股票
        dp[0][1][1] = -prices[0];
        // 交易 2 次， 没有持有股票， 股票价格一天不会变化，一买一卖， 赚的钱为 0
        dp[0][2][0] = 0;
        // 交易 2次，一买一卖， 还持有，不可能存在
        dp[0][2][1] = -100001;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= 2; j++)
            {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j - 1][0] - prices[i], dp[i - 1][j][1]);
            }
        }
        return max(dp[n-1][2][0],dp[n-1][1][0]);
    }
};
// @lc code=end

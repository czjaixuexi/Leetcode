// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem188.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
// dp[i][j][0] 表示第 x 天，  j交易次数， 未持有股票的最大利润
// dp[i][j][1] 表示第 x 天，  j交易次数， 持有的股票最大利润
// dp[i][j][0] = max(dp[i-1][j][0],dp[i-1][j][1]+prices[i])
// dp[i][j][1] = max(dp[i-1][j-1][0]-prices[i],dp[i-1][j][1])
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        int dp[n][k + 1][2];
        memset(dp, 0, sizeof dp);
        //初始化第一天
        for (int i = 0; i <= k; i++)
        {
            if (i % 2) //交易奇数次
            {
                dp[0][i][0] = -1001;
                dp[0][i][1] = -prices[0];
            }
            else
            {
                dp[0][i][1] = -1001;
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j - 1][0] - prices[i], dp[i - 1][j][1]);
            }
        }
        int res = 0;
        for (int i = 1; i <= k; i++)
        {
            res = max(res, dp[n - 1][i][0]);
        }
        return res;
    }
};
// @lc code=end

// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem322.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
//dp[j]表示凑成j最少需要的硬币数量
//dp[j] = min(dp[j], dp[j - coins[i]] + 1)
//dp[0]=0
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, INT_MAX - 1);
        dp[0] = 0;
        for (int j = 1; j <= amount; j++)
        {
            for (int i = 0; i < coins.size(); i++)
            {
                if (j - coins[i] >= 0)
                {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX - 1 ? -1 : dp[amount];
    }
};
// @lc code=end

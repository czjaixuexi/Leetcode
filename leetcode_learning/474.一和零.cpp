// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem474.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
// dp[i][j][k]表示在前i个字符串中，能够获得j个0和k个1的最长字符串数量
// if ((j-当前字符串0的个数)>=0 && (k-当前字符串1的个数)>=0) dp[i][j][k] = max(dp[i-1][j][k],dp[i-1][j-zeros][k-ones]+1);
// else 保持不变 dp[i][j][k] = dp[i-1][j][k];
class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int length = strs.size();
        vector<vector<vector<int>>> dp(length + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        for (int i = 1; i <= length; i++)
        {
            int zeros = count(strs[i - 1].begin(), strs[i - 1].end(), '0');
            int ones = count(strs[i - 1].begin(), strs[i - 1].end(), '1');
            for (int j = 0; j <= m; j++)
            {
                for (int k = 0; k <= n; k++)
                {
                    if ((j - zeros) >= 0 && (k - ones) >= 0)
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - zeros][k - ones] + 1);
                    else
                        dp[i][j][k] = dp[i - 1][j][k];
                }
            }
        }
        return dp[length][m][n];
    }
};
// @lc code=end

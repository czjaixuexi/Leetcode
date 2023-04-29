// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem279.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
// dp[j]表示凑成j最少需要的完全平方数个数
// dp[j] = min(dp[j], dp[j - i*i] + 1)
// dp[0]=0
class Solution
{
public:
    int numSquares(int n)
    {
        int num = (int)sqrt(n);

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int j = 1; j <= n; j++)
        {
            for (int i = 0; i <= num; i++)
            {
                if (j - i * i >= 0 && dp[j - i * i] != INT_MAX)
                {
                    dp[j] = min(dp[j], dp[j - i * i] + 1);
                }
            }
        }
        return dp[n];
    }
};

// @lc code=end

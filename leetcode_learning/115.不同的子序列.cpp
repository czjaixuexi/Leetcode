// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem115.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
// dp[i][j]：以i-1为结尾的s子序列中出现以j-1为结尾的t的个数为dp[i][j]
// 如果 s[i-1] != t[j-1]， 有 dp[i][j] = dp[i-1][j]
// 如果 s[i-1] == t[j-1] ， 有 dp[i][j] = dp[i-1][j-1] + dp[i - 1]

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        unsigned int dp[s.size() + 1][t.size() + 1];
        for (int i = 0; i <= s.size(); i++)
            dp[i][0] = 1;
        for (int j = 1; j <= t.size(); j++)
            dp[0][j] = 0;
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= t.size(); j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[s.size()][t.size()];
    }
};
// @lc code=end

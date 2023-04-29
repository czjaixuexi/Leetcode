// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem392.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
// dp[i][j] 表示s的[0..i-1] 在是否为t中的[0..j-1]的子串
// if(s[i-1]==t[i-1]) dp[i][j] = dp[i-1][j-1];
// else dp[i][j] = dp[i][j-1]
// dp[0][j] = true, 其他为false
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(t.size() + 1, false));
        for (int j = 0; j <= t.size(); j++)
        {
            dp[0][j] = true;
        }
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= t.size(); j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[s.size()][t.size()];
    }
};
// @lc code=end

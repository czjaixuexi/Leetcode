// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem516.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
// dp[i][j]表示以s[i]开头 s[j]为结尾最长回文子序列
// if s[i] == s[j]
// 情况一：下标i 与 j相同，同一个字符例如a，当然是回文子串 dp[i][j] = 1 //省略
// 情况二：下标i 与 j相差为1，例如aa，也是回文子串 dp[i][j] = 2
// 情况三：下标：i 与 j相差大于1的时候，例如cabac，此时s[i]与s[j]已经相同了，dp[i][j] = dp[i + 1][j - 1] + 2;
// else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
//  初始化 dp[i][j]全为1
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 1));
        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    if (j - i == 1)
                    { //情况2
                        dp[i][j] = 2;
                    }
                    else if (j - i > 1)
                    {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][s.size() - 1];
    }
};
// @lc code=end

// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem583.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
// dp[i][j]：以i-1为结尾的字符串word1，和以j-1位结尾的字符串word2，想要达到相等，所需要删除元素的最少次数。
// 如果 s[i-1] == t[j-1]s[i−1]==t[j−1] ， 有 dp[i][j] = dp[i-1][j-1]dp[i][j]=dp[i−1][j−1]
//  else s[i−1]!=t[j−1]， 有 dp[i][j] = min({dp[i - 1][j - 1] + 2, dp[i - 1][j] + 1, dp[i][j - 1] + 1})

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int dp[word1.size() + 1][word2.size() + 1];
        for (int i = 0; i <= word1.size(); i++)
            dp[i][0] = i;
        for (int j = 0; j <= word2.size(); j++)
            dp[0][j] = j;
        for (int i = 1; i <= word1.size(); i++)
        {
            for (int j = 1; j <= word2.size(); j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min({dp[i - 1][j - 1] + 2, dp[i - 1][j] + 1, dp[i][j - 1] + 1});
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
// @lc code=end

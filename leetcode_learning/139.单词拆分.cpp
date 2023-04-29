// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem139.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
// dp[j]表示前j个字符是否可以由wordDict中的单词构成
// dp[j] 由[i,j]范围内的字符是否出现在字典中，以及dp[i]是否为true确定
// dp[0] = true
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordset(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int j = 1; j <= s.size(); j++)
        { //遍历背包
            for (int i = 0; i < j; i++)
            { //遍历物品
                string word = s.substr(i, j - i);
                if (wordset.find(word) != wordset.end() && dp[i])
                {
                    dp[j] = true;
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end

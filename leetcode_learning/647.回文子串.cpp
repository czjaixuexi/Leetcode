// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem647.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
// dp[i][j]表示[i..j]范围是否为回文串
// if s[i] == s[j]
// 情况一：下标i 与 j相同，同一个字符例如a，当然是回文子串
// 情况二：下标i 与 j相差为1，例如aa，也是回文子串
// 情况三：下标：i 与 j相差大于1的时候，例如cabac，此时s[i]与s[j]已经相同了，
//  我们看i到j区间是不是回文子串就看aba是不是回文就可以了，那么aba的区间就是 i+1 与 j-1区间，这个区间是不是回文就看dp[i + 1][j - 1]是否为true
// else dp[i][j] = false;
class Solution
{
public:
    int countSubstrings(string s)
    {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int res = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    if (j - i <= 1)
                    {
                        //情况一和二
                        res++;
                        dp[i][j] = true;
                    }
                    else if (dp[i + 1][j - 1])
                    {
                        //情况三
                        res++;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

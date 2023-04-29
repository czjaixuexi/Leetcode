// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1035.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */

// @lc code=start
// dp[i][j] 表示1中的以nums1[i-1]为末尾的前i个 和2中以nums2[j-1]为末尾的前j个中的最多连线数量
// if(tex1[i-1]==nums1[j-1]) dp[i][j] = dp[i-1][j-1]+1
// else dp[i][j] = max(d[i-1][j],dp[i][j-1])
class Solution
{
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int res = 0;
        for (int i = 1; i <= nums1.size(); i++)
        {
            for (int j = 1; j <= nums2.size(); j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[nums1.size()][nums2.size()];
    }
};
// @lc code=end

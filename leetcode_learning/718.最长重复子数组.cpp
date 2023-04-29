// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem718.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
// dp[i][j] 表示nums1 的以nums1[i-1]为末尾的前i个 和nums2中以nums[j-1]为末尾的前j个中的最长子数组长度
// if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
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
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};
// @lc code=end

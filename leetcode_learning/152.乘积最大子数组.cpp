// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem152.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

 // @lc code=start
 /**
  * dp[i][0]： 从第 0 项到第 i 项范围内的子数组的最小乘积,有以下几种可能
  * 不和别人乘，就 nums[i]自己
  * nums[i] 是负数，希望乘上前面的最大积
  * nums[i] 是正数，希望乘上前面的最小积
  * dp[i][1]： 从第 0 项到第 i 项范围内的子数组的最大乘积,有以下几种可能:
  * 不和别人乘，就 nums[i]自己
  * nums[i] 是负数，希望乘上前面的最小积
  * nums[i] 是正数，希望乘上前面的最大积
  * dp[i][0]=min(dp[i-1][0]*nums[i],min(dp[i-1][1]*nums[i],nums[i]))
  * dp[i][1]=max(dp[i-1][0]*nums[i],max(dp[i-1][1]*nums[i],nums[i]))
  * 初始化
  * dp[0][0] = nums[0]
  * dp[0][1] = nums[1]
  * 正向遍历一遍
  */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        vector<vector<int>> dp(nums.size(), vector<int>(2));
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        for (int i = 1;i < nums.size();i++) {
            dp[i][0] = min(dp[i - 1][0] * nums[i], min(dp[i - 1][1] * nums[i], nums[i]));
            dp[i][1] = max(dp[i - 1][0] * nums[i], max(dp[i - 1][1] * nums[i], nums[i]));
            res = max(dp[i][1], res);
        }
        return res;
    }
};
// @lc code=end


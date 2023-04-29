// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem300.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
// dp[j] 表示以下标j结尾的字符的最长子序列长度
// 位置i的最长升序子序列等于j从0到i-1各个位置的最长升序子序列 + 1 的最大值。
// if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
// 初始化dp[j] = 1
// 两层循环，内外都正向
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }

                
            }
        }
        return dp[nums.size()-1];
    }
};
// @lc code=end

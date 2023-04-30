// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem189.h"
#include"algorithm"
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size();
        // 翻转数组
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
// @lc code=end

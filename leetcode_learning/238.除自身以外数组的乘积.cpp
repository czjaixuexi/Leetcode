// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem238.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> res(nums.size(), 1);
        // 先用res暂存nums[i]左边的乘积
        for (int i = 1; i < nums.size(); i++)
        {
            res[i] = nums[i - 1] * res[i - 1];
        }
        // 再将res[i]乘以num[i]右边的乘积
        int r = 1;
        for (int j = nums.size() - 1; j >= 0; j--)
        {
            res[j] *= r;
            r *= nums[j];
        }
        return res;
    }
};
// @lc code=end

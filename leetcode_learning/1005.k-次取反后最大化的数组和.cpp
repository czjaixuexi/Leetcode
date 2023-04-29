// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1005.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        for (auto a : nums)
        {
            if (a < 0 && k > 0)
            {
                a = -a;
                k--;
            }
        }
        if (k % 2 == 1)
        {
            sort(nums.begin(), nums.end());
            nums[0] = -nums[0];
        }
        int res = 0;
        for (auto a : nums)
        {
            res += a;
        }
        return res;
    }
};

// @lc code=end

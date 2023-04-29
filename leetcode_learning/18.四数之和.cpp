// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem18.h"
#include "algorithm"
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
// 思路与15.三数之和相同，外面再加一层for循环即可
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++)
        {
            //剪枝
            if (nums[k] > target && nums[k] >= 0)
                break;

            //去重nums[k]
            if (k > 0 && nums[k] == nums[k - 1])
                continue;
            //里面就是三数之和的求法
            for (int i = k + 1; i < nums.size(); i++)
            {
                //剪枝
                if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0)
                    break;
                //去重nums[i]
                if (i > k + 1 && nums[i] == nums[i - 1])
                    continue;
                int left = i + 1;
                int right = nums.size() - 1;
                while (left < right)
                {
                    if ((long)nums[k] + nums[i] + nums[left] + nums[right] > target)
                        right--;
                    else if ((long)nums[k] + nums[i] + nums[left] + nums[right] < target)
                        left++;
                    else
                    {
                        res.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        // 对nums[left]和nums[right]去重
                        while (right > left && nums[right] == nums[right - 1])
                            right--;
                        while (right > left && nums[left] == nums[left + 1])
                            left++;

                        // 找到答案时，双指针同时收缩
                        right--;
                        left++;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

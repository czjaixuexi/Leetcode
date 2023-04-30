// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem977.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> res(nums.size());
        int k = nums.size() - 1;
        // 双指针遍历，一个从头，一个从尾，每次比较两个指针对应的平方数，选择较大的那个逆序放入答案并移动指针
        for (int i = 0, j = nums.size() - 1; i <= j;)
        {
            if (nums[i] * nums[i] > nums[j] * nums[j])
            {
                res[k--] = nums[i] * nums[i];
                i++;
            }
            else
            {
                res[k--] = nums[j] * nums[j];
                j--;
            }
        }
        return res;
    }
};
// @lc code=end

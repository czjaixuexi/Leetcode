// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem153.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        // 二分查找
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int middle = left + (right - left) / 2;
            // 说明最小值在middle的右侧
            if (nums[middle] > nums[right])
            {
                left = middle + 1;
            }
            // 说明最小值在middle的左侧, 由于每个数值不同，因此不会出现相等的情况
            else 
            {
                right = middle;
            }
        }
        return nums[left];
    }
};

// @lc code=end

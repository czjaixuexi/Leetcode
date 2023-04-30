// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem704.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size();
        //[left,right)的左闭右开区间
        while (left < right)
        {
            int middle = left + (right - left) / 2; // 防止溢出 等同于(left + right)/2
            if (nums[middle] > target)
            { // 中间值大于目标值，说明目标值在左区间所以后续判断[left, middle)
                right = middle;
            }
            else if (nums[middle] < target)
            { // 中间值小于目标值，说明目标值在右区间所以后续判断[middle + 1, right]
                left = middle + 1;
            }
            else // 说明middle==target, 返回middle
                return middle;
        }
        // 未找到目标值
        return -1;
    }
};
// @lc code=end

// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem33.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            if (nums[middle] == target)
                return middle;

            // [left,middle]是顺序区间
            if (nums[left] <= nums[middle])
            {
                // target在[left,middle）区间内
                if (target >= nums[left] && target < nums[middle])
                {
                    right = middle - 1;
                }

                else
                {
                    left = middle + 1;
                }
            }
            // [middle,right]是顺序区间
            else
            {
                // target在（middle,right]区间内
                if (target > nums[middle] && target <= nums[right])
                {
                    left = middle + 1;
                }
                else
                {
                    right = middle - 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

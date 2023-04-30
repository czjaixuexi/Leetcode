// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        // 双指针法
        int fast = 0;
        int slow = 0;
        // 快慢指针，快指针指向的值不为val时候， nums[slow] = nums[fast], slow往前进一位
        for (; fast < nums.size(); fast++)
        {
            if (nums[fast] != val)
            {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};
// @lc code=end

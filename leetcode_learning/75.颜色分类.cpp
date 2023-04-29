// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem75.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
// j的左边是0，j位置待定
// k的右边是2，k位置待定
// i是遍历数组指针
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0, j = 0, k = n - 1; i <= k;)
        {
            if (nums[i] == 0)
                swap(nums[i++], nums[j++]);
            else if (nums[i] == 2)
                swap(nums[i], nums[k--]);
            else
                i++;
        }
    }
};
// @lc code=end

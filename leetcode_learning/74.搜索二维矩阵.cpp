// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem74.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        const int m = matrix.size();
        const int n = matrix[0].size();
        // 二分法，二维矩阵版
        // 这里使用[left,right)左闭右开区间
        int left = 0;
        int right = m * n;
        while (left < right)
        {
            int middle = left + (right - left) / 2;
            int x = matrix[middle / n][middle % n];
            // 去左区间继续查找
            if (x > target)
            {
                right = middle;
            }
            // 去右区间继续查找
            else if (x < target)
            {
                left = middle + 1;
            }
            // 相等
            else
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

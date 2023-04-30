// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem59.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int loop = n / 2; // 定义循环几轮，例如n为奇数3，那么loop = 1 只是循环一圈，矩阵中间的值需要单独处理

        // 每一轮循环后，左边界加一位，右边界收缩一位
        int startx = 0, starty = 0;     // 定义起始坐标点
        int endx = n - 1, endy = n - 1; // 定义终止坐标点
        int count = 1;                  // 定义循环计数器
        int i, j;
        while (loop--)
        {
            i = startx;
            j = starty;
            // 模拟第一排从左往右(左闭右开)
            for (; j < endy; j++)
            {
                res[i][j] = count++;
            }
            // 模拟最右列从上往下(左闭右开)
            for (; i < endx; i++)
            {
                res[i][j] = count++;
            }
            // 模拟最下列从右往左(左闭右开)
            for (; j > starty; j--)
            {
                res[i][j] = count++;
            }
            // 模拟最左列从下往上
            for (; i > startx; i--)
            {
                res[i][j] = count++;
            }

            // 下一轮，起始点位置加1
            startx++;
            starty++;
            // 终止点位置-1
            endx--;
            endy--;
        }
        // 循环完成，若n为奇数，还需要在中心再加一个数
        if (n % 2)
        {
            res[n / 2][n / 2] = count;
        }
        return res;
    }
};
// @lc code=end

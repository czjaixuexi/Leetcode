// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem64.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

 // @lc code=start
 /**
  * dp[i][j]表示以grid[i][j]为路径终点的最小总和
  * dp[i][j] = min(dp[i-1][j] + grid[i][j], dp[i][j-1]+grid[j])
  * 初始化
  * dp[0][0] = grid[0][0]
  * dp[i][0] = dp[i-1][0] + grid[i][0]
  * dp[0][j] = dp[0][j-1] + grid[0][j]
  * 两层循环，外层从上到下，内层从左到右
  */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int rows = grid.size();
        const int columns = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(columns));
        // 初始化
        dp[0][0] = grid[0][0];
        for (int i = 1;i < rows; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < columns; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        // 遍历
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < columns; j++) {
                dp[i][j] = min(dp[i - 1][j] + grid[i][j], dp[i][j - 1] + grid[i][j]);
            }
        }
        return dp[rows - 1][columns - 1];
    }
};
// @lc code=end


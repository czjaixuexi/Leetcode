// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem79.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

 // @lc code=start
class Solution {
public:
    // 表示以board[i][j]为首字母，是否能够找到匹配的单词
    bool backtrack(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int step, int i, int j) {
        // 该位置已被访问 或 单词不匹配，返回false
        if (visited[i][j] || board[i][j] != word[step]) {
            return false;
        }
        // 最后一个字母也匹配，找到单词，返回true
        if (step == word.size() - 1) {
            return true;
        }
        visited[i][j] = true;         //设置为被访问过

        // 向左遍历
        if (i - 1 >= 0 && backtrack(board, word, visited, step + 1, i - 1, j)) {
            return true;
        }
        // 向上遍历
        if (j - 1 >= 0 && backtrack(board, word, visited, step + 1, i, j - 1)) {
            return true;
        }
        // 向下遍历
        if (i + 1 < board.size() && backtrack(board, word, visited, step + 1, i + 1, j)) {
            return true;
        }
        // 向右遍历
        if (j + 1 < board[0].size() && backtrack(board, word, visited, step + 1, i, j + 1)) {
            return true;
        }
        visited[i][j] = false;        //撤销遍历标记
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        const int rows = board.size();
        const int columns = board[0].size();
        // 标记数组，false表示未访问，true表示已访问
        vector<vector<bool>> visited(rows, vector<bool>(columns, false));
        for (int i = 0;i < rows; i++) {
            for (int j = 0;j < columns; j++) {
                if (backtrack(board, word, visited, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end


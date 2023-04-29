/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int n, int k, int startindex)
    {
        if (path.size() == k)
        {
            res.push_back(path);
            return;
        }
        for (int i = startindex; i <= n - (k - path.size()) + 1; i++)
        {
            /* code */
            path.push_back(i);         //处理结点
            backtracking(n, k, i + 1); //递归
            path.pop_back();           //回溯
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        backtracking(n, k, 1);
        return res;
    }
};
// @lc code=end

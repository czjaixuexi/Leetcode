/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    int sum = 0;
    void backtracking(int k, int n, int sum, int startindex)
    {
        if (sum > n)
            return;
        if (path.size() == k && sum == n)
        {
            res.push_back(path);
            return;
        }
        for (int i = startindex; i <= 9 - (k - path.size()) + 1; i++)
        {
            sum += i;
            path.push_back(i);              //处理单个结点
            backtracking(k, n, sum, i + 1); //递归
            path.pop_back();                //回溯
            sum -= i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        backtracking(k, n, sum, 1);
        return res;
    }
};
// @lc code=end

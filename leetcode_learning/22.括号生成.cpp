// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem22.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution
{
public:
    vector<string> res;
    string path;
    void dfs(int left, int right, const int n)
    {
        //右括号已插满，说明此时搜索完毕
        if (right == n)
        {
            res.emplace_back(path);
            return;
        }
        //尝试插入左括号
        if (left < n)
        {
            path.push_back('(');
            dfs(left + 1, right, n);
            path.pop_back(); //回溯
        }
        //尝试插入右括号
        if (right < left)
        {
            path.push_back(')');
            dfs(left, right + 1, n);
            path.pop_back(); //回溯
        }
    }
    vector<string> generateParenthesis(int n)
    {
        res.clear();
        path.clear();
        dfs(0, 0, n);
        return res;
    }
};
// @lc code=end

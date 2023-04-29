/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> res;
    vector<string> path;
    //判断回文
    bool ishuiwen(string s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
        {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }

    void backtracking(string s, int index)
    {
        //若Index>=s.size(),说明已经找到一组分割方案
        if (index >= s.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); i++)
        {
            if (ishuiwen(s, index, i)) //是回文,将其切割加入路径
            {
                string str = s.substr(index, i - index + 1);
                path.push_back(str);
            }
            else
            {
                continue;
            }
            backtracking(s, i + 1); //递归
            path.pop_back();        //回溯
        }
    }

    vector<vector<string>> partition(string s)
    {
        backtracking(s,0);
        return res;
    }
};
// @lc code=end

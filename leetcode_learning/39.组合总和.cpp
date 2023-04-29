/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    int sum = 0;
    void backtracking(vector<int> &candidates, int target, int sum, int index)
    {
        // if (sum > target)
        //     return;
        if (sum == target)
        {
            res.push_back(path);
            return;
        }

        for (int i = index; i < candidates.size() && sum + candidates[i] <= target; i++)
        {
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {   sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, sum, 0);
        return res;
    }
};
// @lc code=end

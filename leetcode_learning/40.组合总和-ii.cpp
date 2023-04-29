// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem40.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
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
        if (sum == target)
        {
            res.push_back(path);
            return;
        }
        for (int i = index; i < candidates.size() && sum + candidates[i] <= target; i++)
        {
            //去除已经重复的
            if (i > index && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, target, sum, i + 1);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, sum, 0);
        return res;
    }
};
// @lc code=end

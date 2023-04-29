/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int> &nums)
    {
        if (path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }
        int used[21] = {0};
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[nums[i]+10]==1)
                continue; //该数字已经被收入集合，跳过

            else
            {
                used[nums[i]+10] = 1;
                path.push_back(nums[i]);
                backtracking(nums);
                path.pop_back();
                //used[nums[i]+10] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        //vector<bool> used(nums.size(), false); //用于记录元素是否被使用
        backtracking(nums);
        return res;
    }
};
// @lc code=end

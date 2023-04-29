// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem47.h"
#include "algorithm"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    bool used[8]; //用于标记纵向是否重复
    void backtrack(vector<int>& nums){
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        //vector<bool> useheng(21,false); //用于标记同一层是否重复(横向)
        for(int i = 0;i<nums.size();i++){
            if(i>0 && nums[i] == nums[i-1] && used[i-1] == false) continue;
            if(used[i]) continue; //纵向有重复，跳过
            used[i] = true;
            path.push_back(nums[i]);
            backtrack(nums);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        path.clear();
        res.clear();
        memset(used,false,sizeof(used));
        sort(nums.begin(), nums.end()); // 排序
        backtrack(nums);
        return res;
    }
};
// @lc code=end

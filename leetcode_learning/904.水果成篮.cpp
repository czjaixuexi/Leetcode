/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int start=0,end=0,res=0;
        unordered_map<int,int> mp;//用于记录当前水果的种类
        //滑动窗口法，遍历窗口的右边界
        while(end<nums.size()){
            mp[nums[end]]++;   //若当前种类小于2种，则右边界继续右移,
            while(mp.size()>2){//若当前左边界下，种类大于2种，则左边界持续右移
                mp[nums[start]]--;
                if(mp[nums[start]]==0) mp.erase(nums[start]);
                start++;
            }
            res=max(res,end-start+1);
            end++;
        }
        return res;
    }
};
// @lc code=end


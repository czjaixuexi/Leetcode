/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0,end=0,sum=0,res=nums.size()+1;
        
        //滑动窗口法，遍历窗口的右边界
        while(end<nums.size()){
            sum+=nums[end];
            while(sum>=target){//若左边界满足条件，则左边界右移，缩小范围继续判断
                res=min(res,end-start+1);
                sum-=nums[start++];
            }
            end++;
        }
        return res==nums.size()+1?0:res;
    }
};
// @lc code=end


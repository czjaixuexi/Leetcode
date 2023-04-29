/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        //考虑目标值在数组中的情况:
        while(left<=right){  //在左闭右闭区间内查找, [left,right]
        int middle=left+(right-left)/2;//防止数据溢出，等价于middle=(right+left)/2
        if(nums[middle]>target){ //nums[middle]>目标值，说明目标值在左区间，接下来在[left,middle-1]中查找
            right=middle-1;
        }
        else if(nums[middle]<target){//nums[middle]<目标值，说明目标值在右区间，接下来在[middle+1,right]中查找
            left=middle+1;
        }
        else //说明nums[middle]==target，返回middle
        return middle;
        }
        //目标不在数组中，考虑目标能插入位置的情况:
        //1.目标值插入到最左侧， 应该插入位置0  此时[left,right]=[0,-1]
        //2.目标值插入到最右侧，应该插入位置nums.size()-1, 此时[left,right]=[nums.size()-1,nums.size()-2] 
        //3.目标值插入到数组中间的某个位置， 此时 return right+1
        //综上所示，这三种情况都返回right+1
        return right+1;
          }
};
// @lc code=end


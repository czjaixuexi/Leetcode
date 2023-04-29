/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
//寻找左边界
int searchleft (vector<int>& nums, int target){
    int left=0;
    int right = nums.size()-1;
    int leftborder=-1; //记录左边界
    while(left<=right){//在左闭右闭区间内查找, [left,right]
        int middle = left+(right-left)/2;//防止数据溢出，等价于middle=(right+left)/2
        if (nums[middle]<target){ //nums[middle]<目标值，说明目标值在右区间，接下来在[middle+1,right]中查找 
            left = middle+1;
        }
        else if (nums[middle]>target)  //nums[middle]>target的情况, 说明目标值在左区间, 继续在[left, middle-1]中寻找
        {
            right=middle-1;
        }
        else //nums[middle]==target的情况，要找到最左侧的target就必须在[left,middle-1]寻找
        {   
            leftborder=middle;
            right = middle-1;
        }

    }
    return leftborder;
}

//寻找左边界
int searchright (vector<int>& nums, int target){
    int left=0;
    int right = nums.size()-1;
    int rightborder = -1; //记录右边界
    while(left<=right){//在左闭右闭区间内查找, [left,right]
        int middle = left+(right-left)/2;//防止数据溢出，等价于middle=(right+left)/2
        if (nums[middle]>target){ //nums[middle]>目标值，说明目标值在左区间，接下来在[left,right-1]中查找 
            right=middle-1;
        }
        else if(nums[middle]<target) //nums[middle]<target的情况, 说明目标值在右区间, 继续在[middle+1, right]中寻找
        {
            left = middle + 1;
            
        }
        else   //nums[middle]==target的情况，要找到最右侧的target就必须在[middle+1,right]寻找
        {
            rightborder=middle;
            left=middle+1;
        }
    }
    return rightborder;
}


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {searchleft(nums,target),searchright(nums,target)};
    }
};
// @lc code=end


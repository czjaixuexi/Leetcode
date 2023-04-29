// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include<bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int p= 0, q= nums.size()-1, count=nums.size();
        
        //双指针法，将值为val的元素置换到数组的末尾
        while(p<q){
            while(nums[q]==val&&p<q) q--; //q从末尾向前遍历指向第一个不为val的元素
            while(nums[p]!=val&&p<q) p++; //p从首部向后遍历，指向第一个为val的元素
            swap(nums[q],nums[p]);        //交换pq所指元素
 
        }
        //记录一共有多少个值为val的元素.
         for(int j = nums.size()-1;j>=0&&nums[j]==val;j--)
        {
            count--;
        }
        return count;
    }
};
// @lc code=end


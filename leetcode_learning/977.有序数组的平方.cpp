// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem977.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {  
        for(auto &k:nums){
            k=k*k;
        }
        const int len=nums.size()-1;
        vector<int> res(len+1);
        int k=len;
        
        //双指针遍历，归并数组
        for(int i=0,j=len;i<=j;){
            if(nums[i]>nums[j]) 
            {res[k--]=nums[i];
                i++;   
                }
            else{
                res[k--]=nums[j];
                j--;
            }
        }

        return res;
    }
};
// @lc code=end


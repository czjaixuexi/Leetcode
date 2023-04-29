// @before-stub-for-debug-begin
#include <vector>
#include <string>

#include "commoncppproblem283.h"
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        for(auto &j:nums){
            if(j) swap(j,nums[i++]);
        }

        }
    };

    //双指针法
// @lc code=end


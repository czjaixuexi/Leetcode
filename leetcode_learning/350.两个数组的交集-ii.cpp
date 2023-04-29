/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int a[1001]={0};
        vector<int> res;
        for(auto k:nums1){
            a[k]++;
        }
        for(auto k:nums2){
            if(a[k]-->0) res.push_back(k);
        }
        return res;
    }
};
// @lc code=end


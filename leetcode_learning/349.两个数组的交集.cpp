/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        vector<int> res;
        for(auto k:nums1){
            if(map.find(k)==map.end())
            map[k]++;
        }
        for(auto k:nums2){
            if(map.find(k)!=map.end())
            map[k]--;
        }
        for(auto k:map){
            if(k.second<=0) res.push_back(k.first);
        }
        return res;
    }
};
// @lc code=end


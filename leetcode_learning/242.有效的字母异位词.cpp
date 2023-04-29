/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26]={0};
        for(auto k:s){
            a[k-'a']++;
        }
        for(auto k:t){
            a[k-'a']--;
        }
        for(auto k:a){
            if(k)return false;
        }
        return true;
    }
};
// @lc code=end


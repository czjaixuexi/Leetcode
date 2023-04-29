/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }

        int a[26]={0};
        for(auto b:magazine){
            a[b-'a']++;
        }
        for(auto b:ransomNote){
            a[b-'a']--;
        }
        for(auto b:a){
            if(b<0) return false;
        }
        return true;
    }
};
// @lc code=end


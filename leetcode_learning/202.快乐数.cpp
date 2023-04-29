/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while(n!=1){
            if(set.find(n)==set.end()) set.insert(n);
            else 
            return false;
            n=happy(n);
        }
        return true;
    }

    int happy(int n){
        int res=0;
        while(n!=0){
            res+=(n%10)*(n%10);
            n=n/10;
        }
        return res;
    }

};
// @lc code=end


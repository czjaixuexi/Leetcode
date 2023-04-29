// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem76.h"
#include"unordered_map"
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        if (s==t) return s;
        if(s.length()<t.length()) return "";
        int begin=0;
        int end=0;
        int n = s.length();
        unordered_map<char,int> map;
        int leftwindow=-1,rightwindow=-1;
        for(auto &k:t){
            map[k]++;
        }
        //滑动窗口法，遍历窗口的右边界
        while(end<s.length()){
            if(map.find(s[end])!=map.end()){
                map[s[end]]--;
            }
            
            while(ismatch(map)){//若左边界满足条件，则左边界右移，缩小范围继续判断
                if(n>=end-begin+1)
                {   n=end-begin+1;
                    leftwindow=begin;
                    rightwindow=end;}
                if(map.find(s[begin])!=map.end())
                {
                    map[s[begin]]++;
                 }
                 begin++;
            }
            end++;
        }
        return leftwindow==-1?"":s.substr(leftwindow,rightwindow-leftwindow+1);
    }
    //用于判断左边界是否满足条件
    bool ismatch(unordered_map<char,int> map){
        for(auto &k:map){
            if(k.second>0) return false;
        }
        return true;
    }
};

// @lc code=end


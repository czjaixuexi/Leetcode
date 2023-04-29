// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem541.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        int i=0;
        for(int j=0;j<s.size();j+=(2*k)){
            if(s.size()-j<k) 
            {   
                reverseString(s,j,s.size()-1);
            }
            else{
                reverseString(s,j,j+k-1);
            }
        }
        return s;
    }

    void reverseString(string& s,int start,int end) {
        for(int i = start,j=end;i<j;i++,j--){
            swap(s[i],s[j]);
        }
    }
};
// @lc code=end


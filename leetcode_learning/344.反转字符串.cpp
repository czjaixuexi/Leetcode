// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem344.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0,j=s.size()-1;i<j;i++,j--){
            swap(s[i],s[j]);
        }
    
    }
};
// @lc code=end


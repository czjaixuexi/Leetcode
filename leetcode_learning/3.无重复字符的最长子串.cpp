// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include<bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */


// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
        {
            return 0;
        }
        map<char, int> map;
        int count = 0, res = 0,j=0;
        for (int i = 0; i < s.size(); i++)
        {
  
            if (!map.count(s[i]))
            {
                count++;
          
            }
            else
            {
                j=max(map[s[i]],j);
                count = i - j;
            }
            map[s[i]] = i;
            res = max(count, res);
        }
        return res;
    }
};
// @lc code=end


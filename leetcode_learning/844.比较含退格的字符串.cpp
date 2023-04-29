/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
//得到去掉回退后的字符串
string backsapce(string s){
    string res;
    for(auto &a:s)
    {
        if (a!='#') 
        {
            res.push_back(a);
        }
        else if(!res.empty())
           res.pop_back();
    }
    return res;
}

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return backsapce(s)==backsapce(t);
    }
};
// @lc code=end


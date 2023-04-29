/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        //将字符串的元素依次入栈
        //栈空时，元素入栈
        //栈非空时，比较栈顶元素与s[i]：
        //若相同：则栈顶元素出栈，i++
        //若不相同，则s[i]入栈,i++
        stack<char> res;
        for(auto k:s){
            if(res.empty()) res.push(k);
            else{
                if(res.top()==k){
                    res.pop();
                }
                else{
                    res.push(k);
                }
            }
        }
        string ans(res.size(),' ');
        for(int i=ans.size()-1;i>=0;i--){
            ans[i] = res.top();
            res.pop();
        }
        return ans;
    }
};
// @lc code=end


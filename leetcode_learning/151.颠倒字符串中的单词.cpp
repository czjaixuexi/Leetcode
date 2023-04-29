// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem151.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 颠倒字符串中的单词
 */

// @lc code=start
class Solution {
public:
    //1.双指针法删除字符串中多余的空格
    void removespace(string &s){
        int slow = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){//删除每个空格，只对单词做处理
                if(slow!=0) s[slow++]=' ';//在每个单词之间添加空格
                while(i<s.size()&&s[i]!=' '){
                    s[slow++]=s[i++];
                }
            }
        }
        s.resize(slow);
    }
    //翻转字符串
    void reverse(string &s,int start,int end){
        for(;start<end;start++,end--){
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
        }
    }

    
    string reverseWords(string s) {
        removespace(s);
        reverse(s,0,s.size()-1); //先翻转字符串
        //再翻转字符串中每个单词
        for(int i=0;i<s.size();i++){
            int start = i;
            while(i<s.size()&&s[i]!=' '){
                i++;
            }
            reverse(s,start,i-1);
        }
        return s;
    }
};
// @lc code=end


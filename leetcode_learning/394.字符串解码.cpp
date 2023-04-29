// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem394.h"
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution
{
public:
    string decodeString(string s)
    {
        stack<char> st;
        string res = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ']')
            { //将栈内与该]匹配的部分弹出 k[str]
                string str = "";
                while (!st.empty() && st.top() != '[')
                {
                    str = st.top() + str;
                    st.pop();
                }
                st.pop(); //将[弹出
                //记录需要复制的次数
                string numstr = "";
                while (!st.empty() && (st.top() >= '0' && st.top() <= '9'))
                {
                    numstr = st.top() + numstr;
                    st.pop();
                };
                int num = stoi(numstr);
                //复制[]内的字符串,用temp记录
                string temp = "";
                for (int i = 0; i < num; i++)
                {
                    temp += str;
                }
                //重新入栈
                for (int i = 0; i < temp.size(); i++)
                {
                    st.push(temp[i]);
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        while (!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};
// @lc code=end

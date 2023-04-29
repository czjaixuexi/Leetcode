// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    //用于判断两个栈顶元素是否匹配
    bool ismatch(char a, char b)
    {
        if ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'))
        {
            return true;
        }
        return false;
    }
    bool isValid(string s)
    {
        stack<char> left; //用来存储左括号
        if (s.size() % 2)
            return false; //如果长度是奇数，直接返回
        for (auto k : s)
        {
            //若是左括号，将其左括号入栈内
            if (k == '(' || k == '[' || k == '{')
            {
                left.push(k);
            }
            else //判断该右括号是否匹配
            {
                if (left.empty() || !ismatch(left.top(), k))
                    return false;

                left.pop();
            }
        }
        return left.empty();
    }
};
// @lc code=end

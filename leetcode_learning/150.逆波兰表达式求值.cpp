/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //后缀表达式
        //通过栈实现，如果是数字，则依次入栈
        //如果是运算符，则提取出栈内的两个数字，运算后将结果放入栈内
        stack<int> num;
        for(auto c:tokens){
            if(c=="+"||c=="-"||c=="/"||c=="*"){
                int a = num.top();
                num.pop();
                int b = num.top();
                num.pop();
                if (c == "+") num.push(b + a);
                if (c == "-") num.push(b - a);
                if (c == "*") num.push(b * a);
                if (c == "/") num.push(b / a);
            }
            else
            {
                num.push(stoi(c));
            }
        }
            return num.top();
    }
};
// @lc code=end


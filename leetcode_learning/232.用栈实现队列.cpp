// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem232.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue
{
public:
    stack<int> in;
    stack<int> out;
    MyQueue()
    {
    }

    void push(int x)
    {
        in.push(x);
    }

    int pop()
    {
        if (!out.empty())
        {
            int temp = out.top();
            out.pop();
            return temp;
        }
        while (!in.empty())
        {
            out.push(in.top());
            in.pop();
        }
        int temp = out.top();
        out.pop();
        return temp;
    }

    int peek()
    {
        if (!out.empty())
            return out.top();
        while (!in.empty())
        {
            out.push(in.top());
            in.pop();
        }
        return out.top();
    }

    bool empty()
    {
        if (in.empty() && out.empty())
            return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

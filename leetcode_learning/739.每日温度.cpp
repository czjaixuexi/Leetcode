// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem739.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        // 递增栈
        stack<int> st;
        vector<int> result(T.size(), 0);
        for (int i = 0; i < T.size(); i++)
        {

            //若当前的值大于栈顶的值，则计算下标之差即为天数差，并将栈顶弹出
            while (!st.empty() && T[i] > T[st.top()])
            {
                result[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};
// @lc code=end

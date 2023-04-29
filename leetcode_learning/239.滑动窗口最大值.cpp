// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem239.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
//定义一个单调队列， 队列内元素从大到小排列，出口元素的值最大
// push时，若新加入的元素大于入口元素的值，则将入口元素的值弹出，直到新加入的元素为最小值为止(新加入的值一定比在队列中的元素后退出窗口)
// pop 若窗口移动时，消除的元素值等于出口元素的值，则将出口元素的值弹出，否则不用进行任何操作

class Solution
{
public:
    class mydeque
    {
    public:
        deque<int> que;
        // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
        // 同时pop之前判断队列当前是否为空。
        void pop(int value)
        {
            if (!que.empty() && que.front() == value)
                que.pop_front();
        }
        // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
        // 这样就保持了队列里的数值是单调从大到小的了。
        void push(int value)
        {
            while (!que.empty() && value > que.back())
            {
                que.pop_back();
            }
            que.push_back(value);
        }
        // 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
        int front()
        {
            return que.front();
        }
    };

    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        mydeque que;
        vector<int> res;

        //先将第一个窗口中的元素加入队列
        for (int i = 0; i < k; i++)
        {
            que.push(nums[i]);
        }
        res.push_back(que.front());
        for (int i = k; i < nums.size(); i++)
        {
            que.pop(nums[i - k]); //移除滑动窗口最前端的元素
            que.push(nums[i]);    //将新的元素加入队列
            res.push_back(que.front());
        }
        return res;
    }
};
// @lc code=end

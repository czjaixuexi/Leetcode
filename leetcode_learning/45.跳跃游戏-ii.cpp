// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem45.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;
        int res = 0, cur = 0, next = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            next = max(i + nums[i], next); //记录下一个到达的最远距离
            if (cur == i)
            {                               //到达当前的最远距离
                if (cur != nums.size() - 1) //如果不是最后一个位置，则计数器+1
                {
                    res++;
                    cur = next; //记录下一个到达的最远距离
                    if (next >= nums.size() - 1)
                        break;
                }
                else
                    break;
            }
        }
        return res;
    }
};
// @lc code=end

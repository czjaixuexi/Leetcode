// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem55.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int max_path = 0;       //能够跳到的最右端的位置
        if (nums.size() == 1)
            return true; //只有一个元素
        for (int i = 0; i <= max_path; i++) //遍历能够跳到的所有位置
        {
            max_path = max(i + nums[i], max_path);//找出当前范围内的下一步能够移动到的最大位置
            if (max_path >= nums.size() - 1) //到达末端
                return true;
        }
        return false;
    }
};
// @lc code=end

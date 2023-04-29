/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int cur = 0;
        int start = 0;
        int toltal = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            /* code */
            cur += gas[i] - cost[i];    //记录当前的油量
            toltal += gas[i] - cost[i]; //记录总共油量与消耗油量
            if (cur < 0)                //若当前油量小于0，说明至少需要从下一个位置开始
            {
                start = i + 1;
                cur = 0;                //重置当前的油量
            }
        }
        if (toltal < 0)
            return -1;
        return start;
    }
};
// @lc code=end

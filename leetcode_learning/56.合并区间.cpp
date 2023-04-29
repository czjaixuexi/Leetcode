// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem56.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution
{
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        if (intervals.size() <= 1)
            return intervals;
        vector<vector<int>> res;
        bool flag = false; //用于判断最后一个区间是否合并
        sort(intervals.begin(), intervals.end(), cmp);

        for (int i = 1; i < intervals.size(); i++)
        {
            int left = intervals[i - 1][0];
            int right = intervals[i - 1][1];
            while (i < intervals.size() && intervals[i][0] <= right) //当前元素的左边界，小于等于前一个元素的右边界，存在重叠
            {
                right = max(intervals[i][1], right); //不断更新右边界
                if (i == intervals.size() - 1)
                    flag = true; //最后一个区间被合并
                i++;
            }
            res.push_back({left, right});
        }
        if (!flag)
            res.push_back(*(intervals.end() - 1)); //若最后一个区间未合并，则将其加入
        return res;
    }
};
// @lc code=end

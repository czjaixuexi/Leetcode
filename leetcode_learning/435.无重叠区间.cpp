// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem435.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution
{
public:
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        
         return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.size()<=1) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int res = 0;
        for (int i = 1; i < intervals.size(); i++)
        {   
            if(intervals[i][0]<intervals[i-1][1])   //若后一个区间的左边界小于前一个区间的右边界，说明两者有重叠，移除后边界
            {
                res++;
                intervals[i][1] = min(intervals[i-1][1],intervals[i][1]);
            }
        }
        return res;
        
    }
};
// @lc code=end


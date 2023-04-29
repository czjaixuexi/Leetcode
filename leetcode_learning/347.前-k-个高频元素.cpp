// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem347.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution
{
public:
    //小根堆
    class mycomparison
    {
    public:
        bool operator()(const pair<int, int> &l, const pair<int, int> &r)
        {
            return l.second > r.second;
        }
    };

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        //先用map记录每个元素出现的次数
        unordered_map<int, int> map;
        for (auto k : nums)
        {
            map[k]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> que; //定义一个小根堆

        for (auto c : map)
        {   
            que.push(c);
            if(que.size()>k)
            que.pop();
        }

        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(que.top().first);
            que.pop();
        }
        return res;
    }
};
// @lc code=end

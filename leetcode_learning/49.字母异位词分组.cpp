// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "commoncppproblem49.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> map;
        //将原strs中的每个字符串都排序，字母异位词排序后的结果应该相同，通过map存储
        for (auto &a : strs)
        {
            string temp = a;
            sort(temp.begin(), temp.end());
            map[temp].emplace_back(a);
        }
        for (auto &a : map)
        {
            result.emplace_back(a.second);
        }
        return result;
    }
};
// @lc code=end

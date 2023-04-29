// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem454.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        //将1和2的各个元素的和为一组，3和4的各个元素的和为一组，
        //将第一组的值通过哈希表记录，再遍历第二组寻找哈希表中是否有满足要求的值
        unordered_map<int, int> sum; // key值为第一组的和，value为该值出现的次数
        int count = 0;
        for (auto a : nums1)
        {
            for (auto b : nums2)
            {
                sum[a + b]++;
            }
        }
        for (auto a : nums3)
        {
            for (auto b : nums4)
            {
                if (sum.find(0 - a - b) != sum.end())
                {
                    count += sum[0 - a - b];
                }
            }
        }
        return count;
    }
};
// @lc code=end

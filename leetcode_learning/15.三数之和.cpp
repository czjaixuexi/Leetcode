// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem15.h"
#include "algorithm"
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
/*
特判，对于数组长度 nnn，如果数组为 nullnullnull 或者数组长度小于 333，返回 [][][]。
对数组进行排序。
遍历排序后数组：
若 nums[i]>0nums[i]>0nums[i]>0：因为已经排序好，所以后面不可能有三个数加和等于 000，直接返回结果。
对于重复元素：跳过，避免出现重复解
令左指针 L=i+1L=i+1L=i+1，右指针 R=n−1R=n-1R=n−1，当 L<RL<RL<R 时，执行循环：
当 nums[i]+nums[L]+nums[R]==0nums[i]+nums[L]+nums[R]==0nums[i]+nums[L]+nums[R]==0，执行循环，判断左界和右界是否和下一位置重复，去除重复解。并同时将 L,RL,RL,R 移到下一位置，寻找新的解
若和大于 000，说明 nums[R]nums[R]nums[R] 太大，RRR 左移
若和小于 000，说明 nums[L]nums[L]nums[L] 太小，LLL 右移
*/
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        //找出nums[i] + nums[left] + nums[right] = 0
        for (int i = 0; i < nums.size(); i++)
        {
            //若第一个数就大于0，则直接返回空集
            if (nums[i] > 0)
                return res;
            //对nums[i]去重
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                // 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
                /*
                while (right > left && nums[right] == nums[right - 1]) right--;
                while (right > left && nums[left] == nums[left + 1]) left++;
                */
                if (nums[i] + nums[left] + nums[right] > 0)
                    right--;
                else if (nums[i] + nums[left] + nums[right] < 0)
                    left++;
                else
                {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    //去重left和right
                    while (right > left && nums[right] == nums[right - 1])
                        right--;
                    while (right > left && nums[left] == nums[left + 1])
                        left++;
                    // 找到答案时，双指针同时收缩
                    right--;
                    left++;
                }
            }
        }
        return res;
    }
};
// @lc code=end

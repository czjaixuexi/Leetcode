// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem31.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

 // @lc code=start
 // 将一个左边的「较小数」与一个右边的「较大数」交换,要让这个「较小数」尽量靠右，而「较大数」尽可能小。
 // 当交换完成后，「较大数」右边的数需要按照升序重新排列。
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = nums.size() - 1;
        // 从后往前寻找第一个逆序的值的下标
        while (index > 0 && nums[index] <= nums[index - 1]) {
            index--;
        }
        // 将index之后数值逆序
        reverse(nums.begin() + index, nums.end());  //逆序
        if (index > 0) {
            // 寻找第一个大于较小数的值，交换位置
            for (int i = index;i < nums.size();i++) {
                if (nums[i] > nums[index - 1]) {
                    swap(nums[i], nums[index - 1]);
                    break;
                }
            }
        }
    }
};
// @lc code=end


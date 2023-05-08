/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

 // @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 异或运算
        int res = 0;
        for (auto a : nums) {
            res ^= a;
        }
        return res;
    }
};
// @lc code=end


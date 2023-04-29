// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem503.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {

        vector<int> nums1(nums);
        nums1.insert(nums1.end(), nums.begin(), nums.end()); // 将两个nums拼接在一起
        vector<int> result(nums1.size(), -1);
        if (nums.size() == 0)
            return result;
        //递增栈
        stack<int> st;
        for (int i = 0; i < nums1.size(); i++)
        {
            //若当前的值大于栈顶的值，记录当前元素即为第一个更大的元素，并将栈顶弹出
            while (!st.empty() && nums1[i] > nums1[st.top()])
            {
                result[st.top()] = nums1[i];
                st.pop();
            }
            st.push(i);
        }
        // 最后再把结果集即result数组resize到原数组大小
        result.resize(nums1.size() / 2);
        return result;
    }
};
// @lc code=end

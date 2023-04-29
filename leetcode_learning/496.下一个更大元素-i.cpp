// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem496.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> result(nums1.size(), -1);
        if (nums1.size() == 0)
            return result;
        //记录nums2各个元素的下一个更大元素
        stack<int> st;
        unordered_map<int, int> map;
        for (int i = 0; i < nums2.size(); i++)
        {
            //若当前的值大于栈顶的值，记录当前元素即为第一个更大的元素，并将栈顶弹出
            while (!st.empty() && nums2[i] > st.top())
            {
                map[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i++)
        {
            if (map[nums1[i]])
                result[i] = map[nums1[i]];
        }
        return result;
    }
};
// @lc code=end

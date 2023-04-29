// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem530.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//中序遍历迭代法
class Solution
{
public:
    int getMinimumDifference(TreeNode *root)
    {
        stack<TreeNode *> st;
        if (root)
            st.push(root);
        TreeNode *pre = nullptr;
        int minval = INT_MAX;
        while (!st.empty())
        {
            TreeNode *cur = st.top();
            if (cur != nullptr)
            {
                st.pop(); //将该结点弹出，避免重复操作
                if (cur->right)
                    st.push(cur->right);
                st.push(cur);
                st.push(nullptr);
                if (cur->left)
                    st.push(cur->left);
            }
            else
            {
                st.pop();
                cur = st.top(); //处理当前结点
                st.pop();
                if (pre!=nullptr)
                    minval = min(minval, abs(cur->val - pre->val));
                pre = cur;
            }
        }
        return minval;
    }
};
// @lc code=end

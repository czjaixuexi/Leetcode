// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem226.h"
#include "stack"
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
// 递归法
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return root;
        swap(root->left, root->right); // 中
        invertTree(root->left);        // 左
        invertTree(root->right);       // 右
        return root;
    }
};
// 迭代法
class solution
{
public:
    TreeNode *invert(TreeNode *root)
    {
        stack<TreeNode *> st;
        if (root)
            st.push(root);
        while (!st.empty())
        {
            auto node = st.top();
            st.pop();
            swap(node->left, node->right);
            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
        }
        return root;
    }
};
// @lc code=end

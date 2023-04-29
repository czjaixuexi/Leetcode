/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == p || root == q || root == nullptr)
            return root;                                           //终止条件
        TreeNode *left = lowestCommonAncestor(root->left, p, q);   //左
        TreeNode *right = lowestCommonAncestor(root->right, p, q); //右
        if (left && right)
            return root; //左右均不为空，说明p,q在root的左右子树，直接返回
        else if (!left && right)
            return right; //左为空，右不为空，返回右
        else if (left && !right)
            return left; //左不为空，右为空，返回左
            return nullptr; //左右均为空，返回nullptr
    }
};
// @lc code=end

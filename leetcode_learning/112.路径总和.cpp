/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
//递归法
class Solution
{
public:
    bool helper(TreeNode *root, int targetSum)
    {
        if (!root->left && !root->right && targetSum == 0)
            return true; //叶子结点，且路径和为目标值
        if (!root->left && !root->right)
            return false; //叶子结点，且路径和不为目标值
        if (root->left)
        { // 左 （空节点不遍历）
            // 遇到叶子节点返回true，则直接返回true
            if (helper(root->left, targetSum - root->left->val))
                return true; // 注意这里有回溯的逻辑
        }
        if (root->right)
        { // 右 （空节点不遍历）
            // 遇到叶子节点返回true，则直接返回true
            if (helper(root->right, targetSum - root->right->val))
                return true; // 注意这里有回溯的逻辑
        }
        return false;
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;

        return helper(root, targetSum - root->val);
    }
};
// @lc code=end

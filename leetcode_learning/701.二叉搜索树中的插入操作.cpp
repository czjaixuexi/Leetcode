/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if(!root) return new TreeNode(val);
        TreeNode *cur = root;
        while (cur)
        {
            if (cur->val < val)
            {
                if (cur->right == nullptr)
                {
                    cur->right = new TreeNode(val);
                    break;
                }
                else
                {
                    cur = cur->right;
                    continue;
                }
            }
            else{
                if(cur->left==nullptr){
                    cur->left = new TreeNode(val);
                    break;
                }
                else {
                    cur = cur->left;
                    continue;
                }
            }
        }
        return root;
    }
};
// @lc code=end

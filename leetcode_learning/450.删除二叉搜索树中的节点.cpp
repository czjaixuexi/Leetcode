/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return nullptr; //遍历到空节点，返回NULL

        if (root->val == key)
        { //找到该结点
            //情况1，左右孩子均为空，则直接删除返回空节点
            if (!root->left && !root->right)
            {
                delete root;
                return nullptr;
            }
            //情况2，左孩子为空，右孩子不为空，删除结点后返回其右孩子
            else if (!root->left)
            {
                auto temp = root->right;
                delete root;
                return temp;
            }
            //情况3,右孩子为空，左孩子不为空，删除结点后返回左孩子
            else if (!root->right)
            {
                auto temp = root->left;
                delete root;
                return temp;
            }
            //情况4，左右孩子均不为空，将左孩子结点转移到右孩子的左子树的最左侧
            else
            {
                auto cur = root->right;
                while (cur->left)
                {
                    cur = cur->left;
                }
                cur->left = root->left;
                auto temp = root->right;
                delete root;
                return temp;
            }
        }
        if (root->val > key)
            root->left = deleteNode(root->left, key);
        if (root->val < key)
            root->right = deleteNode(root->right, key);
        return root;
    }
};
// @lc code=end

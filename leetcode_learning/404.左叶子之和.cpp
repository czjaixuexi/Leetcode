/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int sumOfLeftLeaves(TreeNode *root)
    {   
        if(root==nullptr) return 0;
        int leftval = sumOfLeftLeaves(root->left);  //左
        int rightval = sumOfLeftLeaves(root->right);//右

        //中
        int midval = 0;
        if (root->left && !root->left->left && !root->left->right)
        {   //左叶子结点
            midval = root->left->val;
        }
        int sum = leftval + rightval +midval;
        return sum;
    }
};
// @lc code=end

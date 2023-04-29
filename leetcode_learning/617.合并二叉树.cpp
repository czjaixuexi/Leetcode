/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
//迭代法，层序遍历
class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr)
            return root2;
        if (root2 == nullptr)
            return root1;
        queue<TreeNode *> que;
        que.push(root1);
        que.push(root2);
        while (!que.empty())
        {
            TreeNode *node1 = que.front();
            que.pop();
            TreeNode *node2 = que.front();
            que.pop();
            node1->val += node2->val; //都不为空，则相加

            if (node1->left && node2->left)
            { //左结点均不为空
                que.push(node1->left);
                que.push(node2->left);
            }
            if (node1->right && node2->right) //右结点均不为空
            {
                /* code */
                que.push(node1->right);
                que.push(node2->right);
            }
            if (!node1->left && node2->left)
            { // root1的左节点为空，root2的左节点不为空，则覆盖,此处无需考虑root2为空，因为返回的是root1
                node1->left = node2->left;
            }
            if (!node1->right && node2->right)
            { // root1的右节点为空，root2的右节点不为空，则覆盖,此处无需考虑root2为空，因为返回的是root1
                node1->right = node2->right;
            }
        }
        return root1;
    }
};
// @lc code=end

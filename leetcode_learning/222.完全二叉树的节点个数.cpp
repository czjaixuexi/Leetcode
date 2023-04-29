// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem222.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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

// //递归法
// class Solution
// {
// public:
//     int countNodes(TreeNode *root)
//     {
//         if (!root)
//             return 0;
//         int leftnum = countNodes(root->left);   //左
//         int rightnum = countNodes(root->right); //右
//         int res = leftnum + rightnum + 1; //中
//         return res;
//     }
// };

// //迭代法
// class Solution
// {
// public:
//     int countNodes(TreeNode *root)
//     {
//         queue<TreeNode *> que;
//         if (root != nullptr)
//             que.push(root);
//         int res = 0;
//         while (!que.empty())
//         {
//             TreeNode *node = que.front();
//             que.pop();
//             res++;
//             if (node->left)
//                 que.push(node->left);
//             if (node->right)
//                 que.push(node->right);
//         }
//         return res;
//     }
// };

//完全二叉树解法
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        auto left = root->left;
        auto right = root->right;
        int leftdepth = 0, rightdepth = 0;// 这里初始为0是有目的的，为了下面求指数方便
        while (left)// 求左子树深度
        {
            leftdepth++;
            left = left->left;
        }
        while (right)// 求右子树深度
        {
            rightdepth++;
            right = right->right;
        }
        if (leftdepth == rightdepth)
        {
            return (2 << leftdepth) - 1;// 注意(2<<1) 相当于2^2，所以leftDepth初始为0
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

// @lc code=end

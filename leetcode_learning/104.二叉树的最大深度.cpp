// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem104.h"
#include <queue>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
//迭代法,层序遍历
// class Solution
// {
// public:
//     int maxDepth(TreeNode *root)
//     {
//         queue<TreeNode *> que;
//         int res = 0;
//         if (root)
//             que.push(root);
//         while (!que.empty())
//         {
//             int size = que.size();
//             res++;
//             for (int i = 0; i < size; i++)
//             {
//                 TreeNode *node = que.front();
//                 que.pop();
//                 if (node->left)
//                     que.push(node->left);
//                 if (node->right)
//                     que.push(node->right);
//             }
//         }
//         return res;
//     }
// };
//递归法，求深度用前序遍历
class Solution
{
public:
    int res;
    void getdepth(TreeNode *node, int depth)
    {
        res = max(res, depth);  //中
        if (node->left == nullptr && node->right == nullptr)
            return; //终止条件，到达叶子结点

        if (node->left) //左
        {
            depth++;
            getdepth(node->left, depth);
            depth--; //回溯
        }
        if (node->right)    //右
        {
            depth++;
            getdepth(node->right, depth);
            depth--; //回溯
        }
        return;
    }
    int maxDepth(TreeNode *root)
    {   if (!root) return 0;
        getdepth(root,1);
        return res;
    }
};
// @lc code=end

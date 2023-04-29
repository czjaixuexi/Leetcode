// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem110.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    // 判断高度需要用到后序遍历
    int getheight(TreeNode *root)
    {
        if (!root)
            return 0;
        int leftheight = getheight(root->left);
        if (leftheight == -1)
            return -1; // 此时已非平衡二叉树，直接返回-1
        int rightheight = getheight(root->right);
        if (rightheight ==-1 )
            return -1; // 此时已非平衡二叉树，直接返回-1

        int result;
        if (abs(leftheight - rightheight) > 1)
        {
            result = -1;
        }
        else
        {
            result = 1 + max(leftheight, rightheight); // 以当前节点为根节点的树的最大高度
        }
        return result;
    }
    bool isBalanced(TreeNode *root)
    {
        return getheight(root) == -1 ? false : true;
    }
};

// @lc code=end

// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem144.h"
#include "stack"
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
//  class Solution {
//  public:
//      void traversal(TreeNode* cur, vector<int>& vec) {
//          if (cur == NULL) return;
//          vec.push_back(cur->val);    // 中
//          traversal(cur->left, vec);  // 左
//          traversal(cur->right, vec); // 右
//      }
//      vector<int> preorderTraversal(TreeNode* root) {
//          vector<int> res;
//          traversal(root,res);
//          return res;
//      }
//  };

// 迭代法
// 先将根结点入栈，再先后将右孩子、左孩子入栈。
// 再依次出栈
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> tmp;
        if (!root)
            return res;
        tmp.push(root);
        while (!tmp.empty())
        {
            auto node = tmp.top();
            tmp.pop();
            res.push_back(node->val);
            if (node->right)
                tmp.push(node->right);
            if (node->left)
                tmp.push(node->left);
        }
        return res;
    }
};
// @lc code=end

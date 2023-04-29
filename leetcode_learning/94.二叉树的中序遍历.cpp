// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem94.h"
#include "stack"
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
// 迭代法
//  class Solution {
//  public:
//      void traversal(TreeNode* cur, vector<int>& vec) {
//          if (cur == NULL) return;
//          traversal(cur->left, vec);  // 左
//          vec.push_back(cur->val);    // 中
//          traversal(cur->right, vec); // 右

//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         traversal(root,res);
//         return res;
//     }
// };

// 迭代法
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> tmp;
        auto cur = root;
        while (cur || !tmp.empty())
        {
            if (cur)
            {
                tmp.push(cur);
                cur = cur->left; // 左
            }
            else
            {
                cur = tmp.top(); // 中
                tmp.pop();
                res.emplace_back(cur->val);
                cur = cur->right; // 右
            }
        }
        return res;
    }
};
// @lc code=end

// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem257.h"
#include <stack>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
// 前序遍历迭代法
//  class Solution
//  {
//  public:
//      vector<string> binaryTreePaths(TreeNode *root)
//      {
//          stack<TreeNode *> st; //用于存放前序遍历的节点
//          stack<string> stpath; //用于存放路径
//          vector<string> res;
//          if (root != nullptr)
//          {
//              st.push(root);
//              stpath.push(to_string(root->val));
//          }
//          while (!st.empty())
//          {
//              TreeNode *node = st.top(); //取出改结点  中
//              st.pop();
//              string path = stpath.top(); //取出改结点对应的路径
//              stpath.pop();
//              if (node->left == nullptr && node->right == nullptr)
//              { //遇到叶子结点，将当前路径存入
//                  res.push_back(path);
//              }

//             if (node->right)
//             {
//                 st.push(node->right);
//                 stpath.push(path + "->" + to_string(node->right->val)); //右
//             }
//             if (node->left)
//             {
//                 st.push(node->left);
//                 stpath.push(path + "->" + to_string(node->left->val)); //左
//             }
//         }
//         return res;
//     }
// };

// 版本二
class Solution
{
private:
    void traversal(TreeNode *cur, string path, vector<string> &result)
    {
        if (!cur)
            return;
        path += to_string(cur->val); // 中
        if (cur->left == NULL && cur->right == NULL)
        {
            result.push_back(path);
            return;
        }
        if (cur->left)
        {
            path += "->";
            traversal(cur->left, path, result); // 左
            path.pop_back();                    // 回溯 '>'
            path.pop_back();                    // 回溯 '-'
        }
        if (cur->right)
        {
            path += "->";
            traversal(cur->right, path, result); // 右
            path.pop_back();                     // 回溯'>'
            path.pop_back();                     // 回溯 '-'
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result;
        string path;
        traversal(root, path, result);
        return result;
    }
};
// @lc code=end

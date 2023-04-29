// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem145.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
// class Solution {
// public:
//     void traversal(TreeNode* cur, vector<int>& vec) {
//         if (cur == NULL) return;
//         traversal(cur->left, vec);  // 左
//         traversal(cur->right, vec); // 右
//         vec.push_back(cur->val);    // 中
//     }
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> res;
//         traversal(root,res);
//         return res;
//     }
// };

//迭代法
//根据前序遍历的迭代法，调整孩子结点的入栈顺序 ： 前序遍历右孩子先入栈，左孩子再入栈，数组中的顺序是中左右
//后续遍历，左孩子先入栈，右孩子再入栈，数组中的顺序是中右左， 再将数组逆序后得到左右中
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
       vector<int> res;
       stack<TreeNode*> tmp;
       if(!root) return res;
       tmp.push(root);
       while(!tmp.empty()){
           auto node = tmp.top();
           tmp.pop();
           res.push_back(node->val);
           if(node->left) tmp.push(node->left);
           if(node->right) tmp.push(node->right);
       }
       reverse(res.begin(),res.end());
       return res;
    }
};
// @lc code=end


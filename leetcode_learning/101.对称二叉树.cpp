// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem101.h"
#include <queue>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
//递归
class Solution {
public:
    bool helper(TreeNode *left, TreeNode *right){
 // 首先排除空节点的情况
        if (left == NULL && right != NULL) return false;
        else if (left != NULL && right == NULL) return false;
        else if (left == NULL && right == NULL) return true;
        // 排除了空节点，再排除数值不相同的情况
        else if (left->val != right->val) return false;

        // 此时就是：左右节点都不为空，且数值相同的情况
        // 此时才做递归，做下一层的判断
        bool outside = helper(left->left, right->right);   // 左子树：左、 右子树：右
        bool inside = helper(left->right, right->left);    // 左子树：右、 右子树：左
        bool isSame = outside && inside;                   // 左子树：中、 右子树：中 （逻辑处理）
        return isSame;
    }
    bool isSymmetric(TreeNode* root) {
       if(!root) return true;
       return helper(root->left,root->right);
    }
};

//迭代法
// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         if (!root) return true;
//         queue<TreeNode*> que;
//         que.push(root->left);   // 将左子树头结点加入队列
//         que.push(root->right);  // 将右子树头结点加入队列
        
//         while (!que.empty()) {  // 接下来就要判断这两个树是否相互翻转
//             TreeNode* leftNode = que.front(); que.pop();
//             TreeNode* rightNode = que.front(); que.pop();
//             if (!leftNode && !rightNode) {  // 左节点为空、右节点为空，此时说明是对称的
//                 continue;
//             }

//             // 左右一个节点不为空，或者都不为空但数值不相同，返回false
//             if ((!leftNode || !rightNode || (leftNode->val != rightNode->val))) {
//                 return false;
//             }
//             que.push(leftNode->left);   // 加入左节点左孩子
//             que.push(rightNode->right); // 加入右节点右孩子
//             que.push(leftNode->right);  // 加入左节点右孩子
//             que.push(rightNode->left);  // 加入右节点左孩子
//         }
//         return true;
//     }
// };
// @lc code=end

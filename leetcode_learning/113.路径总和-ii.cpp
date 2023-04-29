// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem113.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
class Solution {
    public:
    vector<vector<int>>ans;
    vector<int>path;
    void dfs(TreeNode*root,int count){
        if(!root->left&&!root->right&&count==0){
            ans.push_back(path);
            return;
        }
        if(!root->left&&!root->right)return;

        if(root->left){
            count-=root->left->val;
            path.push_back(root->left->val);
            dfs(root->left,count);
            count+=root->left->val;
            path.pop_back();
        } 

        if(root->right){
             path.push_back(root->right->val);
            count-=root->right->val;
            dfs(root->right,count);
            count+=root->right->val;
             path.pop_back();
        }
        return;
    }

   
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        path.clear();
        ans.clear();
        if(root==nullptr)return ans;
        path.push_back(root->val);
        dfs(root,targetSum-root->val);
        return ans;
    }
};

// @lc code=end

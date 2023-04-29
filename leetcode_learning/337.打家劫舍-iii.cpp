// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem337.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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

// 0表示不偷，1表示偷
//若当前结点不偷，则可以偷其左右结点 val = max(left[0], left[1]) + max(right[0], right[1]);
//若偷当前结点，则不可以偷其左右结点 val = root->val + left[0] + right[0];
class Solution
{
public:
    int rob(TreeNode *root)
    {
        vector<int> dp(2, 0);
        dp = helper(root);
        return max(dp[0], dp[1]);
    }
    vector<int> helper(TreeNode *root)
    {
        if (!root)
            return {0, 0};
        vector<int> left = helper(root->left);
        vector<int> right = helper(root->right);

        int val1 = max(left[0], left[1]) + max(right[0], right[1]); //不偷当前结点
        int val2 = root->val + left[0] + right[0];                  //偷当前结点
        return {val1, val2};
    }
};
// @lc code=end

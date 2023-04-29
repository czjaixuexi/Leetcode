/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode *> que;
        vector<int> res;
        if (root)
            que.push(root);

        while (!que.empty())
        {
            int size = que.size();
            int max1 = INT_MIN;
            
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                max1= max(node->val,max1);
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            res.push_back(max1);
        }
        return res;
    }
};
// @lc code=end


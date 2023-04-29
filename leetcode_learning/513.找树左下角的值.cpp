// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem513.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
class Solution
{
public:
    int maxDepth = INT_MIN;
    int result = 0;
    void track(TreeNode *cur, int depth)
    {   
        //终止条件
        if (cur == nullptr)
            return;
        //先递归的左子树，因此会优先更新最左侧的值
        if (cur->left == nullptr && cur->right == nullptr)
        {
            if (depth > maxDepth)
            {
                maxDepth = depth;
                result = cur->val;
            }
        }

        //中，没有中的处理，此处不需要
        track(cur->left, depth + 1); //左
        track(cur->right, depth + 1); //右
    }

    int findBottomLeftValue(TreeNode *root)
    {
        track(root, 0);
        return result;
    }
};
// @lc code=end

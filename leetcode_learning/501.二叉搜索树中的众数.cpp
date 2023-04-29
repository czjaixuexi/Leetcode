/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    vector<int> findMode(TreeNode *root)
    {
        stack<TreeNode *> st;
        if (root)
            st.push(root);
        TreeNode *pre = nullptr;
        int count = 0;
        int maxcount = 0;
        vector<int> res;
        while (!st.empty())
        {
            TreeNode *cur = st.top();
            if (cur != nullptr)
            {
                st.pop(); //将该结点弹出，避免重复操作
                if (cur->right)
                    st.push(cur->right);
                st.push(cur);
                st.push(nullptr);
                if (cur->left)
                    st.push(cur->left);
            }
            else
            {
                st.pop();
                cur = st.top(); //处理当前结点
                st.pop();
                if (pre == nullptr)
                { //第一个节点
                    count = 1;
                }
                else if (pre->val == cur->val)
                { // 如果和最大值相同，放进res中
                    count++;
                }
                else
                {
                    count = 1;
                }
                pre = cur;

                if (count == maxcount)
                {
                    res.push_back(cur->val);
                }

                if (count > maxcount)
                {                     // 如果计数大于最大值频率
                    maxcount = count; // 更新最大频率
                    res.clear();      // 很关键的一步，不要忘记清空res，之前res里的元素都失效了
                    res.push_back(cur->val);
                }
                
            }   
        }
        return res;
    }
};
// @lc code=end

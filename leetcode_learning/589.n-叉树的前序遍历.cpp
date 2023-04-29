/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    void pre(Node *root, vector<int> &vec)
    {
        if (!root)
            return;
        vec.push_back(root->val);
        for (auto a : root->children)
        {
            pre(a, vec);
        }
    }
    vector<int> preorder(Node *root)
    {
        vector<int> res;
        pre(root, res);
        return res;
    }
};
// @lc code=end

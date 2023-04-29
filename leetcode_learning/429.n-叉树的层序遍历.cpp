/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
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
    vector<vector<int>> levelOrder(Node *root)
    {
        queue<Node *> que;
        vector<vector<int>> res;
        if (root)
            que.push(root);

        while (!que.empty())
        {
            int size = que.size();
            vector<int> vec;

            for (int i = 0; i < size; i++)
            {
                Node *node = que.front();
                que.pop();
                vec.push_back(node->val);
                //依次将非空孩子结点入队
                for (int j = 0; j < node->children.size(); j++)
                {
                    if (node->children[j])
                        que.push(node->children[j]);
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};
// @lc code=end

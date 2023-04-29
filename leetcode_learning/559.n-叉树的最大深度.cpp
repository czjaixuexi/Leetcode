/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
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

//递归法
// class Solution
// {
// public:
//     int maxDepth(Node *root)
//     {
//         if (!root)
//             return 0;
//         int depth = 0;
//         for (int i = 0; i < root->children.size(); i++)
//         {
//             /* code */
//             depth = max(depth, maxDepth(root->children[i]));
//         }
//         return depth + 1;
//     }
// };

//迭代法
class Solution
{
public:
    int maxDepth(Node *root)
    {
        queue<Node *> que;
        int depth = 0;
        if (root)
            que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            depth++;
            for (int i = 0; i < size; i++)
            {
                Node *node = que.front();
                que.pop();
                //依次将非空孩子结点入队
                for (int j = 0; j < node->children.size(); j++)
                {
                    if (node->children[j])
                        que.push(node->children[j]);
                }
            }
        }
        return depth;
    }
};
// @lc code=end

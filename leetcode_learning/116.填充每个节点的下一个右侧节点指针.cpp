/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        queue<Node *> que;

        if (root)
            que.push(root);

        while (!que.empty())
        {
            int size = que.size();
            Node *node;
            Node *nodepre;
            for (int i = 0; i < size; i++)
            {   
                node = que.front();
                //获得每层的第一个结点
                if (i == 0)
                {
                    nodepre = que.front();
                    que.pop();
                }
                //每层依次遍历指向下一个结点
                else
                {
                    que.pop();
                    nodepre->next = node;
                    nodepre = node;

                }
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            //每层最后一个结点指向NULL
            nodepre->next = NULL;
        }
        return root;
    }
};
// @lc code=end


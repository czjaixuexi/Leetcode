// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem138.h"
#include <unordered_map>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

 // @lc code=start
 /*
 // Definition for a Node.
 class Node {
 public:
     int val;
     Node* next;
     Node* random;

     Node(int _val) {
         val = _val;
         next = NULL;
         random = NULL;
     }
 };
 */

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map;
        if(head == nullptr) return head;
        auto cur = head;
        //1. 遍历链表，将原节点作为key，拷贝节点作为value保存在map中
        while(cur){
            Node* newNode = new Node(cur->val);
            map[cur] = newNode;
            cur = cur->next;
        }

        //2. 复制链表的next 和 random
        cur = head;
        while(cur){
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }
        return map[head];
    }
};
// @lc code=end


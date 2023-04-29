// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem203.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    //处理头结点
    while (nullptr != head && head->val == val) {
             head = head->next;
     }

       ListNode* pre = new ListNode(0);
       ListNode* cur=head;
       pre->next=cur;
       while(cur!=nullptr){
           if(cur->val==val){
               pre->next=cur->next;
           }
           else{
               pre=cur;
           }
        cur=cur->next;
       }
       return head;
    }
};
// @lc code=end


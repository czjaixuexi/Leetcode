/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //双指针法，快指针先走N步，然后快慢指针同时移动，快指针移动到末端时，慢指针指向倒数第n个结点的前一个结点
        ListNode* dummyhead=new ListNode();
        dummyhead->next=head;
        ListNode* fast=dummyhead;
        ListNode* slow=dummyhead;
        while(n--){
            fast=fast->next;
        }
        while(fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return dummyhead->next;
    }
};
// @lc code=end


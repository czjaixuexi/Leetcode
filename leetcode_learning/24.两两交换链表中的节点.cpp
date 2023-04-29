// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem24.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyhead = new ListNode();
        dummyhead->next=head;//虚拟头结点，方便对头结点进行操作
        ListNode* cur=dummyhead;
        ListNode* temp1; 
        ListNode* temp2; 
        while(cur->next!=nullptr && cur->next->next!=nullptr)
        {
            temp1=cur->next;  
            temp2=cur->next->next;
            
            temp1->next = temp2->next;
            temp2->next = temp1;
            cur->next = temp2;       
            cur=cur->next->next;
        }
        return dummyhead->next;
    }
};
// @lc code=end


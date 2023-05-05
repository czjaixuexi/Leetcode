// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem148.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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

  // 自底向上，进行归并
class Solution
{
public:
    ListNode* sortList(ListNode* head)
    {
        ListNode* dummyHead = new ListNode(0, head);
        auto p = head;
        // 计算链表的长度
        int length = 0;
        while (p) {
            length++;
            p = p->next;
        }
        // 归并
        for (int size = 1;size < length;size <<= 1) {
            auto cur = dummyHead->next;
            auto tail = dummyHead;

            while (cur) {
                auto left = cur;
                auto right = cut(left, size); // left->@->@  |  right->@->@->@...

                cur = cut(right, size); // left->@->@ | right->@->@ |  cur->@->...
                tail->next = merge(left, right);
                // 始终保持tail在尾部
                while (tail->next) {
                    tail = tail->next;
                }
            }
        }
        auto res = dummyHead->next;
        delete dummyHead;
        return res;
    }




    // 切除链表的前n个结点，并返回头结点
    ListNode* cut(ListNode* head, int n)
    {
        auto p = head;
        while (--n && p) {
            p = p->next;
        }
        if (!p) return nullptr;

        auto next = p->next;
        p->next = nullptr;
        return next;
    }


    // 合并两个链表，并返回合并后的头结点
    ListNode* merge(ListNode* list1, ListNode* list2)
    {
        ListNode* dummyHead = new ListNode();
        ListNode* p = dummyHead;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                p->next = list1;
                list1 = list1->next;
            }
            else {
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }
        p->next = (list1 == nullptr ? list2 : list1);
        auto res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};
// @lc code=end

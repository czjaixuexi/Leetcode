/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

 // @lc code=start
 /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
  */
  /**
   * 快慢指针法，分别定义 fast 和 slow 指针，
   * 从头结点出发，fast指针每次移动两个节点，
   * slow指针每次移动一个节点，如果 fast 和 slow指针在途中相遇 ，说明这个链表有环。
   */
class Solution
{
public:
    bool hasCycle(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            // 快慢指针相遇，说明有环
            if (slow == fast)
                return true;
        }
        return false;
    }
};
// @lc code=end

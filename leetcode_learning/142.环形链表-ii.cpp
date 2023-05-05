// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem142.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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

  // 为什么会在slow跑不完一圈就相遇？
  //  假设圈长L
  //  slow进入环的时候，假设fast距离它n步（n<L）
  //  fast一次走两步，slow一次走一步，所以每走一次，它们的距离会缩短1；
  //  那么它们的距离会从n变为n-1,n-2,n-2.....1,0;即不可能只超越而不相遇；
  //  这个过程种slow走了n步，而n<L，即slow用不了一圈就会被追上

  // 1.先判断是否存在环
  // 2.当第一次快慢指针相遇时，说明存在环，此时相遇点在圆内，此时慢指针走过的距离是x+y，快指针走过的距离是x+y+n(z+y)，因为快指针走过的距离是慢指针的2倍，
  // 所以得到等式2（x+y）= x+y+n(z+y),所以x =(n-1)(y+z) + z
  // 3.接下来，令p = head，让p和slow同时再走一段距离为x的路程，二者就在环入口相遇

class Solution
{
public:
    ListNode* detectCycle(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            // 快慢指针相遇
            if (slow == fast)
            {
                auto index1 = head;
                auto index2 = slow;
                while (index1 != index2)
                {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return nullptr;
    }
};
// @lc code=end

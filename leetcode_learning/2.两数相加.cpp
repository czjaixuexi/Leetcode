// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include<bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/* * Definition for singly-linked list.*/
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int count1 = 0, count2 = 0;
		int res1 = 0, res2 = 0, res = 0;
		ListNode* p1 = l1, * p2 = l2, * p = nullptr;
		while (l1 != nullptr)
		{
			res1 = res1 * 10 + l1->val;
			l1 = l1->next;
			count1++;
		}
		while (l2 != nullptr)
		{
			res2 = res2 * 10 + l2->val;
			l2 = l2->next;
			count2++;
		}
		res = res1 + res2;
		count1 >= count2 ? p = p1: p = p2;
		string s = to_string(res);
		for (int i = 0; i < s.size(); i++)
		{
			p->val = s[i] - '0';
			p = p->next;
		}
		return count1 >= count2 ?  p1 : p2;
	}
};
// @lc code=end


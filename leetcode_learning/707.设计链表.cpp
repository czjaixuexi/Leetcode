// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem707.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
public:
    MyLinkedList() {
        dummyhead = new ListNode(0);
        size = 0;
    }
    struct ListNode {
      int val;
      ListNode *next;
      ListNode(int val) : val(val), next(nullptr) {}
    };

    int get(int index) {
        if(index>(size-1) ||index<0)
        return -1;
        ListNode* temp= dummyhead->next;
        while(index--){
            temp=temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        ListNode* temp=new ListNode(val);
        temp->next = dummyhead->next;
        dummyhead->next = temp;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* insert=new ListNode(val);
        ListNode* temp=dummyhead;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=insert;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>size) return;
        else if(index<0) addAtHead(val);
        else if(index==size) addAtTail(val);
        else{
            ListNode* pre=dummyhead;
            while(index--){
            pre=pre->next;
            }
            ListNode* insert=new ListNode(val);
            insert ->next = pre->next;
            pre->next = insert;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index>(size-1) ||index<0)
        return ;
        ListNode* pre=dummyhead;
        ListNode* cur=dummyhead->next;
        while(index--){
            pre=cur;
            cur=cur->next;
        }
        pre->next=cur->next;
        delete cur;
        size--;
    }

    private:
    ListNode* dummyhead;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end


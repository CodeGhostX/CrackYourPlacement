#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* revList(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* fut = NULL;
        if(head) fut = head->next;
        while(fut){
            curr->next = prev;
            prev = curr;
            curr = fut;
            fut = fut->next;
        }
        curr->next = prev;
        return curr;
    }
    ListNode* addNumbers(ListNode* l1, ListNode* l2){
        ListNode* n1 = l1;
        ListNode* n2 = l2;
        int carry = 0;
        ListNode* newHead = NULL;
        ListNode* curr = NULL;
        while(n1 && n2){
            int total = n1->val + n2->val + carry;
            carry = total/10;
            total %= 10;
            ListNode* temp = new ListNode(total);
            if(!newHead){
                curr = temp;
                newHead = temp;
            }
            else{
                curr->next = temp;
                curr = temp;
            }
            n1 = n1->next;
            n2 = n2->next;
        }
        while(n1){
            int total = n1->val + carry;
            carry = total/10;
            total %= 10;
            ListNode* temp = new ListNode(total);
            if(!newHead){
                curr = temp;
                newHead = temp;
            }
            else{
                curr->next = temp;
                curr = temp;
            }
            n1 = n1->next;
        }
        while(n2){
            int total = n2->val + carry;
            carry = total/10;
            total %= 10;
            ListNode* temp = new ListNode(total);
            if(!newHead){
                curr = temp;
                newHead = temp;
            }
            else{
                curr->next = temp;
                curr = temp;
            }
            n2 = n2->next;
        }
        if(carry){
            curr->next = new ListNode(1);
        }
        return newHead;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* list1 = revList(l1);
        ListNode* list2 = revList(l2);
        return revList(addNumbers(list1, list2));
    }
};
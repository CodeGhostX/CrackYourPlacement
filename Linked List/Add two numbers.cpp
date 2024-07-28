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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* n1 = l1;
        ListNode* n2 = l2;
        int carry = 0;
        ListNode* newHead = NULL;
        ListNode* curr = NULL;
        while(n1 && n2){
            int total = n1->val + n2->val + carry;
            if(total>=10){
                carry = 1;
                total -= 10;
            }
            else{
                carry = 0;
            }
            ListNode* temp = new ListNode(total);
            if(!newHead){
                newHead = temp;
                curr = temp;
            }
            else {
                curr->next = temp;
                curr = temp;
            }
            n1 = n1->next;
            n2 = n2->next;
        }
        while(n1){
            int total = n1->val + carry;
            if(total>=10){
                carry = 1;
                total -= 10;
            }
            else{
                carry = 0;
            }
            ListNode* temp = new ListNode(total);
            if(!newHead){
                newHead = temp;
                curr = temp;
            }
            else {
                curr->next = temp;
                curr = temp;
            }
            n1 = n1->next;
        }
        while(n2){
            int total = n2->val + carry;
            if(total>=10){
                carry = 1;
                total -= 10;
            }
            else{
                carry = 0;
            }
            ListNode* temp = new ListNode(total);
            if(!newHead){
                newHead = temp;
                curr = temp;
            }
            else {
                curr->next = temp;
                curr = temp;
            }
            n2 = n2->next;
        }
        if(carry) {
            ListNode* temp = new ListNode(1);
            curr->next = temp;
            curr = temp;
        }
        return newHead;
    }
};
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
    ListNode* getMiddle(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* mergeSortedList(ListNode* first, ListNode* second){
        if(!first) return second;
        if(!second) return first;
        ListNode* n1 = first;
        ListNode* n2 = second;
        ListNode* newHead = NULL;
        ListNode* curr = NULL;
        while(n1 && n2){
            if(n1->val < n2->val){
                if(!curr){
                    newHead = n1;
                    curr = n1;
                } else{
                    curr->next = n1;
                    curr = curr->next;
                }
                n1 = n1->next;
            }
            else{
                if(!curr){
                    newHead = n2;
                    curr = n2;
                } else{
                    curr->next = n2;
                    curr = curr->next;
                }
                n2 = n2->next;
            }
        }
        if(n1) curr->next = n1;
        if(n2) curr->next = n2;
        return newHead;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* middleNode = getMiddle(head);
        ListNode* rightList = middleNode->next;
        ListNode* leftList = head;
        middleNode->next = NULL;
        ListNode* left = sortList(leftList);
        ListNode* right = sortList(rightList);
        return mergeSortedList(left, right);
    }
};
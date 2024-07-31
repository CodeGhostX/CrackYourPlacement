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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessCurr = NULL;
        ListNode* ansHead = NULL;
        ListNode* curr = NULL;
        ListNode* nextHead = NULL;
        ListNode* n = head;
        while(n){
            if(n->val<x){
                if(!lessCurr) {
                    lessCurr = n;
                    ansHead = n;
                }
                else{
                    lessCurr->next = n;
                    lessCurr = lessCurr->next;
                }
            }  
            else{
                if(!curr){
                    curr = n;
                    nextHead = n;
                }
                else{
                    curr->next = n;
                    curr = curr->next;
                }
            }
            n = n->next;
        }
        if(curr) curr->next = NULL;
        if(lessCurr){
            lessCurr->next = nextHead;
            return ansHead;
        }
        else return nextHead;
    }
};
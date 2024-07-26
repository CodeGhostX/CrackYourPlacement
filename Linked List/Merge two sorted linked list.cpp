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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* n1 = list1;
        ListNode* n2 = list2;
        ListNode* curr = NULL;
        ListNode* ans = NULL;
        while(n1 && n2){
            if(n1->val < n2->val){
                if(!ans) ans = n1;
                if(!curr) curr = n1;
                else{
                    curr->next = n1;
                    curr = n1;
                }
                n1 = n1->next;
            }
            else{
                if(!ans) ans = n2;
                if(!curr) curr = n2;
                else {
                    curr->next = n2;
                    curr = n2;
                }
                n2 = n2->next;
            }
        }
        if(n2){
            if(curr) curr->next = n2;
            else return n2;
        }
        if(n1){
            if(curr) curr->next = n1;
            else return n1;
        }
        return ans;
    }
};
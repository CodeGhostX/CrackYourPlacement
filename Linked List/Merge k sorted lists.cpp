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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2){
        if(!head1) return head2;
        if(!head2) return head1;
        ListNode* n1 = head1;
        ListNode* n2 = head2;
        ListNode* curr = NULL;
        ListNode* newHead = NULL;
        while(n1 && n2){
            if(n1->val < n2->val){
                if(!curr) {
                    curr = n1;
                    newHead = n1;
                }
                else{
                    curr->next = n1;
                    curr = curr->next;
                }
                n1 = n1->next;
            }
            else{
                if(!curr) {
                    curr = n2;
                    newHead = n2;
                }
                else{
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* last = NULL;
        for(int i=0;i<n;i++){
            last = mergeTwoLists(last, lists[i]);
        }
        return last;
    }
};
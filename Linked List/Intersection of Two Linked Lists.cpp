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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> first;
        ListNode* n1 = headA;
        ListNode* n2 = headB;
        while(n1){
            first.insert(n1);
            n1 = n1->next;
        }
        while(n2){
            if(first.count(n2)) return n2;
            n2 = n2->next;
        }
        return NULL;
    }
};

// Optimized Approach
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* n1 = headA;
        ListNode* n2 = headB;
        while(n1!=n2){
            if(n1) n1 = n1->next;
            else n1 = headB;

            if(n2) n2 = n2->next;
            else n2 = headA;
        }
        return n1;
    }
};
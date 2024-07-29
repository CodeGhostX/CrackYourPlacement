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
    ListNode* removeNthFromEnd(ListNode* head, int a) {
        ListNode* n = head;
        int count = 0;
        while(n){
            count++;
            n = n->next;
        }
        int d = count-a;
        if(d==0) return head->next;
        count = 0;
        n = head;
        while(n){
            count++;
            if(count==d){
                n->next = n->next->next;
            }
            n = n->next;
        }
        return head;
    }
};
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int count = 0;
        ListNode* n = head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* fut = NULL;
        if(head) fut = head->next;
        ListNode* lastNode = NULL;
        ListNode* nextNode = NULL;
        ListNode* first = NULL;
        ListNode* second = NULL;
        ListNode* newHead = head;
        while(curr){
            count++;
            if(count==left){
                lastNode = prev;
                first = curr;
            }
            if(count==right){
                if(left==1) newHead = curr;
                nextNode = fut;
                second = curr;
            }
            if(count>=left && count<=right){
                curr->next = prev;
            }
            prev = curr;
            curr = fut;
            if(fut)
            fut = fut->next;
        }
        if(first)
        first->next = nextNode;
        if(lastNode)
        lastNode->next = second;
        return newHead;
    }
};
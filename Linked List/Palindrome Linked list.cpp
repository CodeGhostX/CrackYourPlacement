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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* first = revList(slow);
        ListNode* second = head;
        while(first){
            if(first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }
        return true;
    }
};
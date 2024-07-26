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
    int getDecimalValue(ListNode* head) {
        int len = 0;
        ListNode* n = head;
        while(n){
            len++;
            n = n->next;
        }
        n = head;
        int a = len;
        int ans = 0;
        while(n){
            ans += (n->val)*pow(2, a-1);
            a--;
            n = n->next;
        }
        return ans;
    }
};
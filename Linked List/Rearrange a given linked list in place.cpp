#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct Node {
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

class Solution{
public:
    Node* getMiddle(Node* head){
        Node* fast = head;
        Node* slow = head;
        while(fast && fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    Node* revList(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* fut = NULL;
        if(head) fut = head->next;
        while(curr){
            curr->next = prev;
            prev = curr;
            curr = fut;
            if(fut) fut = fut->next;
        }
        return prev;
    }
    void reorderList(Node* head) {
        Node* mid = getMiddle(head);
        Node* second = NULL;
        if(mid){
            second = mid->next;
            mid->next = NULL;
        }
        if(second) second = revList(second);
        Node* curr = NULL;
        Node* n1 = head;
        Node* n2 = second;
        int count = 1;
        while(n1 || n2){
            if(count&1){
                if(!curr) curr = n1;
                else{
                    curr->next = n1;
                    curr = curr->next;
                }
                n1 = n1->next;
            }
            else{
                curr->next = n2;
                n2 = n2->next;
                curr = curr->next;
            }
            count++;
        }
    }
};
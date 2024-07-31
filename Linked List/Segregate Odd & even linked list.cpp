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

class Solution {
  public:
    Node* divide(Node* head) {
        Node* lessCurr = NULL;
        Node* ansHead = NULL;
        Node* curr = NULL;
        Node* nextHead = NULL;
        Node* n = head;
        while(n){
            if(n->data%2==0){
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
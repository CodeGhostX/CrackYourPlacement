#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    vector<Node*> flattenSingle(Node* head){
        Node* n = head;
        Node* tail = NULL;
        while(n){
            Node* next = n->next;
            if(n->child) {
                auto temp = flattenSingle(n->child);
                n->next = temp[0];
                temp[0]->prev = n;
                if(next){
                    next->prev = temp[1];
                    temp[1]->next = next;
                }
                tail = temp[1];
                n->child = NULL;
                n = next;
            } else {
                tail = n;
                n = next;
            }
        }
        return {head, tail};
    }
    Node* flatten(Node* head) {
        return flattenSingle(head)[0];
    }
};
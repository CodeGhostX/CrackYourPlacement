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

class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        int one = 0;
        int zero = 0;
        int two = 0;
        Node* n = head;
        while(n){
            if(n->data==1) one++;
            else if(n->data==2) two++;
            else if(n->data==0) zero++;
            n = n->next;
        }
        n = head;
        while(n){
            if(zero) {
                n->data = 0;
                zero--;
            }
            else if(one){
                n->data = 1;
                one--;
            }
            else {
                n->data = 2;
                two--;
            }
            n = n->next;
        }
        return head;
    }
};
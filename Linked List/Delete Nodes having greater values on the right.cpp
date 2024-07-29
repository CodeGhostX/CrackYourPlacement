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
    Node* revList(Node *head){
        Node* curr = head;
        Node* prev = NULL;
        Node* fut = NULL;
        if(head) fut = head->next;
        while(curr){
            curr->next = prev;
            prev = curr;
            curr = fut;
            if(fut)
            fut = fut->next;
        }
        return prev;
    }
    Node *compute(Node *head)
    {
        vector<int> temp;
        Node* n = head;
        while(n){
            temp.push_back(n->data);
            n = n->next;
        }
        int maxi = INT_MIN;
        Node* curr = NULL;
        Node* newHead = NULL;
        for(int i=temp.size()-1;i>=0;i--){
            if(maxi<=temp[i]){
                maxi = temp[i];
                if(!curr){
                    curr = new Node(maxi);
                    newHead = curr;
                }
                else{
                    curr->next = new Node(maxi);
                    curr = curr->next;
                }
            }
        }
        return revList(newHead);
    }
};
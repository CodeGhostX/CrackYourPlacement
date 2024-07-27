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

class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        long long a = 0;
        long long b = 0;
        Node* n1 = first;
        Node* n2 = second;
        while(n1 || n2){
            if(n1){
                a = (a*10)%1000000007 + n1->data;
                n1 = n1->next;
            }
            if(n2){
                b = (b*10)%1000000007 + n2->data;
                n2 = n2->next;
            }
        }
        return (a*b) % 1000000007;
    }
};
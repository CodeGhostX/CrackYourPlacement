#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> st;
    MyQueue() {
    }
    void push(int x) {
        st.push(x);
    }
    int pop() {
        stack<int> temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        int a;
        if(!temp.empty()) {
            a = temp.top();
            temp.pop();
        }
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        return a;
    }
    int peek() {
        stack<int> temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        int a;
        if(!temp.empty()) a = temp.top();
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        return a;
    }
    bool empty() {
        return st.empty();
    }
};
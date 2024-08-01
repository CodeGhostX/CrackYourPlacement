#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                st.push(s[i]-48);
            }
            else{
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if(s[i]=='+') st.push(a+b);
                if(s[i]=='-') st.push(b-a);
                if(s[i]=='*') st.push(a*b);
                if(s[i]=='/') st.push(b/a);
            }
        }
        return st.top();
    }
};
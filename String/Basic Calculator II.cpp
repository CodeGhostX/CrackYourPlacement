#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int i = 0;
        stack<string> st;
        while(i<n){
            if(s[i]==' ') {
                i++;
                continue;
            }
            if(isdigit(s[i])){
                string num1 = "";
                while(i<n && isdigit(s[i])){
                    num1 += s[i];
                    i++;
                }
                if(!st.empty() && (st.top()=="*" || st.top()=="/")){
                    int num = stoi(num1);
                    string m = st.top();
                    st.pop();
                    string temp = st.top();
                    st.pop();
                    int num2 = stoi(temp);
                    if(m=="*"){
                        long long next = static_cast<long long>(num)*num2;
                        st.push(to_string(next));
                    }
                    else if(m=="/"){
                        long long next = static_cast<long long>(num2)/num;
                        st.push(to_string(next));
                    }
                }
                else{
                    st.push(num1);
                }
            }
            else{
                string temp(1, s[i]);
                st.push(temp);
                i++;
            }
        }
        stack<string> st2;
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }
        while(!st2.empty()){
            string num = st2.top();
            int num1 = stoi(num);
            st2.pop();
            if(st2.empty()) return num1;
            else{
                string m = st2.top();
                st2.pop();
                int num2 = stoi(st2.top());
                st2.pop();
                if(m=="+"){
                    long long next = static_cast<long long>(num1)+static_cast<long long>(num2);
                    st2.push(to_string(next));
                }
                else{
                    long long next = static_cast<long long>(num1)-static_cast<long long>(num2);
                    st2.push(to_string(next));
                }
            }
        }
        return 0;
    }
};
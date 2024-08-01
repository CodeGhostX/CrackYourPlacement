#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string temp1;
        string temp2;
        for(int i=0;i<s.size();i++){
            if(s[i]!='#') temp1.push_back(s[i]);
            else if(temp1.size()) temp1.pop_back();
        }
        for(int i=0;i<t.size();i++){
            if(t[i]!='#') temp2.push_back(t[i]);
            else if(temp2.size()) temp2.pop_back();
        }
        return temp1==temp2;
    }
};
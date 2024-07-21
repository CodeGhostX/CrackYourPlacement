#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void makeParenthesis(string s, int n, int open, int close, vector<string> &ans){
        if(open>n || open<close) return;
        if(open==n && close==n) {
            ans.push_back(s);
            return;
        }
        makeParenthesis(s+'(', n, open+1, close, ans);
        makeParenthesis(s+')', n, open, close+1, ans);
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string> ans;
        makeParenthesis(s, n, 0, 0, ans);
        return ans;
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token = "";
        string result = "";
        while(ss>>token){
            result = token + ' ' + result;
        }
        result.pop_back();
        return result;
    }
};

// Optimized Approach

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        reverse(s.begin(), s.end());
        int i = 0;
        int l = 0;
        int r = 0;
        while(i<n){
            while(i<n && s[i]!=' ') s[r++] = s[i++];
            if(l<r){
                reverse(s.begin()+l, s.begin()+r);
                s[r] = ' ';
                r++;
                l = r;
            }
            i++;
        }
        return s.substr(0, r-1);
    }
};
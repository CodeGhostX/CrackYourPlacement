#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        int n = columnNumber;
        string ans = "";
        while(n){
            n--;
            ans = char(n%26+65) + ans;
            n = n/26;
        }
        return ans;
    }
};
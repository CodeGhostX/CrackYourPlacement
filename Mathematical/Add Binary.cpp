#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int i = a.size()-1;
        int j = b.size()-1;
        string ans = "";
        while(i>=0 && j>=0){
            int sum = a[i]-48 + b[j]-48 + carry;
            if(sum==0) {
                ans = '0' + ans;
                carry = 0;
            }
            else if(sum==1) {
                ans = '1' + ans;
                carry = 0;
            }
            else if(sum==2) {
                ans = '0' + ans;
                carry = 1;
            }
            else if(sum==3) {
                ans = '1' + ans;
                carry = 1;
            }
            if(i==0) cout<<sum;
            i--;
            j--;
        }
        while(i>=0){
            int sum = a[i]-48 + carry;
            if(sum==0) {
                ans = '0' + ans;
                carry = 0;
            }
            else if(sum==1) {
                ans = '1' + ans;
                carry = 0;
            }
            else if(sum==2) {
                ans = '0' + ans;
                carry = 1;
            }
            i--;
        }
        while(j>=0){
            int sum = b[j]-48 + carry;
            if(sum==0) {
                ans = '0' + ans;
                carry = 0;
            }
            else if(sum==1) {
                ans = '1' + ans;
                carry = 0;
            }
            else if(sum==2) {
                ans = '0' + ans;
                carry = 1;
            }
            j--;
        }
        if(carry) ans = '1'+ans;
        return ans;
    }
};
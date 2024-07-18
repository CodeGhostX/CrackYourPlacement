#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.size();i++){
            int j = i;
            int k = 0;
            while(j<haystack.size() && k<needle.size() && haystack[j]==needle[k]){
                j++;
                k++;
            }
            if(k==needle.size()) return i;
        }
        return -1;
    }
};
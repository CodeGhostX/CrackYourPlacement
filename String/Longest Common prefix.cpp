#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int j = 0;
        string ans = "";
        while(j<strs[0].size()){
            int i = 1;
            while(i<strs.size()){
                if(j==strs[i].size() || strs[i][j]!=strs[0][j]) break;
                i++;
            }
            if(i!=strs.size()) return ans;
            else ans += strs[0][j];
            j++;
        }
        return ans;
    }
};
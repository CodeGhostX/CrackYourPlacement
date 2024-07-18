#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         int j = 0;
//         string ans = "";
//         while(j<strs[0].size()){
//             int i = 1;
//             while(i<strs.size()){
//                 if(j==strs[i].size() || strs[i][j]!=strs[0][j]) break;
//                 i++;
//             }
//             if(i!=strs.size()) return ans;
//             else ans += strs[0][j];
//             j++;
//         }
//         return ans;
//     }
// };

// Optimized Approach
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int i = 0;
        while(i<strs[0].size()){
            if(strs[0][i]!=strs.back()[i]) return strs[0].substr(0, i);;
            i++;
        }
        return strs[0].substr(0, i+1);
    }
};
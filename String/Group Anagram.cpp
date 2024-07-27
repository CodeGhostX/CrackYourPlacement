#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> freq;
        for(int i=0;i<strs.size();i++){
            vector<int> flag(26, 0);
            for(int j=0;j<strs[i].size();j++){
                flag[strs[i][j]-'a']++;
            }
            string temp = "";
            for(int j=0;j<26;j++){
                if(flag[j]){
                    int k = flag[j];
                    while(k){
                        temp += char(j+97);
                        k--;
                    }
                }
            }
            freq[temp].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto it : freq){
            ans.push_back(it.second);
        }
        return ans;
    }
};
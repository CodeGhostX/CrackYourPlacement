#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& str) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> freq;
        for(int i=0;i<str.size();i++){
            vector<int> temp(26, 0);
            for(int j=0;j<str[i].size();j++){
                temp[str[i][j]-'a']++;
            }
            string s = "";
            for(int j=0;j<26;j++){
                if(temp[j]){
                    int k = temp[j];
                    while(k){
                        s += char(j+97);
                        k--;
                    }
                }
            }
            freq[s].push_back(str[i]);
        }
        for(auto it: freq){
            ans.push_back(it.second);
        }
        return ans;
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void generatePermutations(unordered_map<int, int> &freq, vector<vector<int>> &ans, vector<int> &temp, int n){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        for(auto it: freq){
            if(it.second>0){
                temp.push_back(it.first);
                freq[it.first]--;
                generatePermutations(freq, ans, temp, n);
                freq[it.first]++;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        vector<vector<int>> ans;
        unordered_map<int, int> freq;
        for(int i=0;i<arr.size();i++){
            freq[arr[i]]++;
        }
        vector<int> temp;
        generatePermutations(freq, ans, temp, n);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
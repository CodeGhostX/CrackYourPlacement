#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;
        for(int i=0;i<t.size();i++){
            freq[t[i]]++;
        }
        int m = s.size();
        int n = t.size();
        int i = 0;
        int j = 0;
        int count_req = n;
        int start_i = i;
        int min_len = INT_MAX;
        while(j<m){
            char ch = s[j];
            if(freq[ch]>0) count_req--;
            freq[ch]--;

            while(count_req==0){
                ch = s[i];
                freq[ch]++;
                if(freq[ch]>0) count_req++;
                int curr_len = j-i+1;
                if(curr_len<min_len){
                    start_i = i;
                    min_len = curr_len;
                }
                i++;
            }
            j++;
        }
        return min_len==INT_MAX ? "" : s.substr(start_i, min_len);
    }
};
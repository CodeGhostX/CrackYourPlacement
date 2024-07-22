#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    string smallestWindow (string s, string t)
    {
        vector<int> freq(26, 0);
        for(int i=0;i<t.size();i++){
            freq[t[i]-97]++;
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
            if(freq[ch-97]>0) count_req--;
            freq[ch-97]--;

            while(count_req==0){
                ch = s[i];
                freq[ch-97]++;
                if(freq[ch-97]>0) count_req++;
                int curr_len = j-i+1;
                if(curr_len<min_len){
                    start_i = i;
                    min_len = curr_len;
                }
                i++;
            }
            j++;
        }
        return min_len==INT_MAX ? "-1" : s.substr(start_i, min_len);
    }
};
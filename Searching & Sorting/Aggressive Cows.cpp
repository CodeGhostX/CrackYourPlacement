#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int noOfCows(vector<int> &stalls, int dist){
        int n = stalls.size();
        int cows = 1;
        int last = stalls[0];
        for(int i=1;i<n;i++){
            if(stalls[i]-last>=dist) {
                cows++;
                last = stalls[i];
            }
        }
        return cows;
    }
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        int start = 1;
        int end = 1e9;
        while(end>=start){
            int mid = (start+end)/2;
            if(noOfCows(stalls, mid)>=k){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return end;
    }
};
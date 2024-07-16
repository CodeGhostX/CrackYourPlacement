#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(), a.end());
        long long mini = INT_MAX;
        for(int i=0;i<n-m+1;i++){
            mini = min(a[i+m-1]-a[i], mini);
        }
        return mini;
    }
};
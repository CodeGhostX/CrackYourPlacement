#include<bits/stdc++.h>
using namespace std;

int findMinimumCost(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());
    int median;
    if(n%2==0){
        int idx = n/2;
        median = (arr[idx]+arr[idx-1])/2;
    }
    else median = arr[n/2];
    int ans = 0;
    for(int i=0;i<n;i++){
        ans += abs(arr[i]-median);
    }
    return ans;
}

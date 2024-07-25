#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the minimum number of swaps required to sort the array.
	int minSwaps(vector<int>&nums)
	{
	    int n = nums.size();
	    vector<pair<int, int>> arr;
	    for(int i=0;i<n;i++){
	        arr.push_back({nums[i], i});
	    }
	    sort(arr.begin(), arr.end());
	    int ans = 0;
	    for(int i=0;i<n;i++){
	        while(arr[i].second!=i){
	            int idx = arr[i].second;
	            ans++;
	            swap(arr[i], arr[idx]);
	        }
	    }
	    return ans;
	}
};
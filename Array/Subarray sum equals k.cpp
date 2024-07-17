#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int total = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            total += nums[i];
            if(total==k) ans++;
            ans += freq[total-k];
            freq[total]++;
        }
        return ans;
    }
};
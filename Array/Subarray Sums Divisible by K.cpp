#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int total = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            total += nums[i];
            int rem = total%k;
            if(rem<0) rem += k;
            ans += freq[rem];
            if(rem==0) ans++;
            freq[rem]++;
        }
        return ans;
    }
};
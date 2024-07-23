#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int med = 0;
        int a = n/2;
        if(n%2==0) med = (nums[a]+nums[a-1])/2;
        else med = nums[a];
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ans += abs(med-nums[i]);
        }
        return ans;
    }
};
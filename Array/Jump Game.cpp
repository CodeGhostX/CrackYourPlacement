#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(pos<i) return false;
            if(nums[i]+i>=pos) pos = nums[i]+i;
        }
        if(pos>=n-1) return true;
        return false;
    }
};
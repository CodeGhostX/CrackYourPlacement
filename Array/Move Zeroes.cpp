#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        int j = 0;
        while(j<n){
            if(nums[j]!=0){
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }
    }
};
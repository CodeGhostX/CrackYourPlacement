#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int n = nums.size();
        int i = 0;
        int j = 0;
        while(j<n){
            while(j<n && nums[i]==nums[j]){
                j++;
            }
            if(i<n && j<n){
                i++;
                swap(nums[i], nums[j]);
            }
            j++;
        }
        return i+1;
    }
};
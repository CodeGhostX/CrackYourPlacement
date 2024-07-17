#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void twoSum(vector<vector<int>> &ans, int i, int target, vector<int>& nums){
        int n = nums.size();
        int s = i+1;
        int e = n-1;
        while(e>s){
            if(nums[s]+nums[e]==target){
                ans.push_back({nums[i], nums[s], nums[e]});
                s++;
                e--;
                while(s<n && nums[s]==nums[s-1]) s++;
                while(e>i && nums[e]==nums[e+1]) e--;
            }
            else if(nums[s]+nums[e]>target) {
                e--;
                while(e>i && nums[e]==nums[e+1]) e--;
            }
            else if(nums[s]+nums[e]<target){
                s++;
                while(s<n && nums[s]==nums[s-1]) s++;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        while(i<n-2){
            twoSum(ans, i, -nums[i], nums);;
            i++;
            while(i<n-2 && nums[i]==nums[i-1]) i++;
        }
        return ans;
    }
};
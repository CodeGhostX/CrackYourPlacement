#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void twoSum(vector<int>& nums, long long target, int i, vector<vector<int>> &ans, int f){
        int s = i+1;
        int n = nums.size();
        int e = n-1;
        while(e>s){
            long long sum = static_cast<long long> (nums[s]) + nums[e];
            if(sum==target){
                ans.push_back({nums[f], nums[i], nums[s], nums[e]});
                e--;
                s++;
                while(e>i && nums[e]==nums[e+1]) e--;
                while(s<n && nums[s]==nums[s-1]) s++; 
            }
            else if(sum>target){
                e--;
                while(e>i && nums[e]==nums[e+1]) e--;
            }
            else{
                s++;
                while(s<n && nums[s]==nums[s-1]) s++;
            }
        }
    }
    void threeSum(vector<int>& nums, long long target, int i, vector<vector<int>> &ans){
        int n = nums.size();
        int j = i+1;
        while(j<n-2){
            twoSum(nums, static_cast<long long>(target)-nums[j], j, ans, i);
            j++;
            while(j<n-2 && nums[j]==nums[j-1]) j++;
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        int i = 0;
        while(i<n-3){
            threeSum(nums, static_cast<long long>(target)-nums[i], i, ans);
            i++;
            while(i<n-3 && nums[i]==nums[i-1]) i++;
        }
        return ans;
    }
};
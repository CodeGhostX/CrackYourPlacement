#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int merge(vector<int>& nums, int i, int mid, int j){
        int count = 0;
        vector<int> temp;
        int left = i;
        int right = mid+1;
        while(left<=mid){
            while(right<=j && (nums[left]*1.0)/2>(nums[right]*1.0)){
                right++;
            }
            count += right - (mid+1);
            left++;
        }
        left = i;
        right = mid+1;
        while(left<=mid && right<=j){
            if(nums[left]<nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=j){
            temp.push_back(nums[right]);
            right++;
        }
        int idx = i;
        for(int a=0;a<temp.size();a++){
            nums[idx] = temp[a];
            idx++;
        }
        return count;
    }
    int mergeSort(vector<int>& nums, int i, int j){
        if(i>=j) return 0;
        int mid = (i+j)/2;
        int left = mergeSort(nums, i, mid);
        int right = mergeSort(nums, mid+1, j);
        int ans = merge(nums, i, mid, j);
        return ans+right+left;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};
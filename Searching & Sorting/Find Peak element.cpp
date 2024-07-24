#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        if(nums[0]>nums[1]) return 0;
        int n = nums.size();
        if(nums[n-1]>nums[n-2]) return n-1;
        int start = 1;
        int end = n-2;
        while(end>=start){
            int mid = (start+end)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
            else if(nums[mid]>nums[mid-1]) start = mid+1;
            else end = mid-1;
        }
        return -1;
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int f = m+n-1;
        int j = n-1;
        int i = m-1;
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[f] = nums1[i];
                i--;
                f--;
            }
            else{
                nums1[f] = nums2[j];
                j--;
                f--;
            }
        }
        while(i>=0){
            nums1[f] = nums1[i];
            i--;
            f--;
        }
        while(j>=0){
            nums1[f] = nums2[j];
            j--;
            f--;
        }
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> ans(n, -1);
        for(int i=0;i<n;i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    while(j<nums2.size()){
                        if(nums1[i]<nums2[j]){
                            ans[i] = nums2[j];
                            break;
                        }
                        j++;
                    }
                    break;
                }
            }
        }
        return ans;
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        long long int total = 1;
        int zero = 0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0)
            total *= nums[i];
            else zero++;
        }
        vector<long long int> ans(n);
        for(int i=0;i<n;i++){
            if(!zero && nums[i]!=0){
                ans[i] = total/nums[i];
            }
            else if(nums[i]==0 && zero==1){
                ans[i] = total;
            }
            else if(zero>1){
                ans[i] = 0;
            }
        }
        return ans;
    }
};

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int el = nums[0];
        for(int i=0;i<nums.size();i++){
            if(count==0){
                el = nums[i];
                count++;
            }
            else if(el==nums[i]) count++;
            else if(el!=nums[i]) count--;
        }
        return el;
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int j = height.size()-1;
        int i = 0;
        int ans = 0;
        while(j>i){
            if(height[j]>height[i]){
                ans = max(ans, height[i]*(j-i));
                i++;
            }
            else{
                ans = max(ans, height[j]*(j-i));
                j--;
            }
        }
        return ans;
    }
};
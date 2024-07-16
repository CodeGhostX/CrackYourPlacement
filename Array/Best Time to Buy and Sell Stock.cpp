#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int ans = 0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<mini) mini = prices[i];
            else ans = max(ans, prices[i]-mini);
        }
        return ans;
    }
};
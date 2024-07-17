#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int mini = INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<mini) mini = prices[i];
            else{
                profit += prices[i]-mini;
                mini = prices[i];
            }
        }
        return profit;
    }
};
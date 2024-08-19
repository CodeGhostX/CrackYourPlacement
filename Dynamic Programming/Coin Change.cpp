class Solution {
public:
    int solve(int total, vector<int>& coins, int idx, vector<vector<int>> &dp){
        if(total<0 || idx==-1) return 1e9;
        if(dp[total][idx]!=-1) return dp[total][idx];
        if(total==0) return 0;
        int a = solve(total-coins[idx], coins, idx, dp) + 1;
        int b = solve(total, coins, idx-1, dp);
        return dp[total][idx] = min({a, b});
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(amount+1, vector<int> (n, -1));
        int a = solve(amount, coins, n-1, dp);
        if(a>=1e9) return -1;
        return a;
    }
};

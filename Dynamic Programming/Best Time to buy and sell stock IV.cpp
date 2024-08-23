class Solution {
public:
    int solve(int state, vector<int>& prices, int idx, int n, int trans, vector<vector<vector<int>>> &dp){
        if( idx==n || trans==0 ) return 0;

        if(dp[idx][trans][state]!=-1) return dp[idx][trans][state];

        // Already Bought
        if(state==1){

            // Skip this index
            int a = solve(1, prices, idx+1, n, trans, dp);

            // Sell at this point
            int b = prices[idx] + solve(0, prices, idx+1, n, trans-1, dp);

            return dp[idx][trans][state] = max(a, b);
        }

        // Not Bought yet
        else{
            // Skip
            int a = solve(0, prices, idx+1, n, trans, dp);

            //Buy at this Point
            int b = solve(1, prices, idx+1, n, trans, dp) - prices[idx];

            return dp[idx][trans][state] = max(a, b);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2, -1)));
        return solve(0, prices, 0, n, k, dp);
    }
};

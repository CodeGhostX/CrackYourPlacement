// Tabulation Solution
class Solution {
  public:
    long long getCount(int n) {
        if(n==1) return 10;
        vector<int> adj[] = {{8}, {2,4}, {1,5,3}, {2,6}, {1,7,5}, {2,8,4,6}, {3,9,5}, {8,4}, {0,7,9,5}, {6, 8}};
        vector<vector<long long>> dp(n, vector<long long>(10, 1));
        long long ans = 0;
        for(int i=0;i<10;i++){
            dp[1][i] = adj[i].size() + 1;
        }
        for(int i=2;i<n;i++){
            for(int j=0;j<10;j++){
                dp[i][j] = 0;
                dp[i][j] += dp[i-1][j];
                for(auto it: adj[j]){
                    dp[i][j] += dp[i-1][it];
                }
            }
        }
        for(int i=0;i<10;i++){
            ans += dp[n-1][i];
        }
        return ans;
    }
};

// Memoization Solution
class Solution {
  public:
    long long solve(int rem, vector<int> adj[], int num, vector<vector<long long>> &dp){
        if(rem==0) return 1;
        if(dp[rem][num] != -1) return dp[rem][num];
        long long total = 0;
        total += solve(rem-1, adj, num, dp);
        for(auto it: adj[num]) total += solve(rem-1, adj, it, dp);
        return dp[rem][num] = total;
    }
    long long getCount(int n) {
        vector<int> adj[] = {{8}, {2,4}, {1,5,3}, {2,6}, {1,7,5}, {2,8,4,6}, {3,9,5}, {8,4}, {0,7,9,5}, {6, 8}};
        vector<vector<long long>> dp(n+1, vector<long long>(10, -1));
        long long ans = 0;
        for(int i=0;i<10;i++){
            ans += solve(n-1, adj, i, dp);
        }
        return ans;
    }
};

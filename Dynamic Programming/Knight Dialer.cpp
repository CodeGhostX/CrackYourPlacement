// Tabulation
class Solution {
public:
    int knightDialer(int n) {
        if(n==1) return 10;
        vector<int> adj[] = {{4,6}, {8,6}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}};
        vector<vector<int>> dp(n, vector<int>(10, 0));

        // Base Case
        for(int i=0;i<10;i++) dp[1][i] = adj[i].size();

        for(int i=2;i<n;i++){
            for(int j=0;j<10;j++){
                int total = 0;
                for(auto it: adj[j]){
                    total += dp[i-1][it];
                    total %= 1000000007;
                }
                dp[i][j] = total;
            }
        }
        int ans = 0;
        for(int i=0;i<10;i++){
            ans += dp[n-1][i];
            ans %= 1000000007;
        }
        return ans; 
    }
};

// Memoization
class Solution {
public:
    int solve(int n, int num, vector<int> adj[], vector<vector<int>> &dp){
        if(n==1) return adj[num].size();
        int total = 0;
        if(dp[n][num]!=-1) return dp[n][num];
        for(auto it: adj[num]){
            total += solve(n-1, it, adj, dp);
            total %= 1000000007;
        }
        return dp[n][num] = total;
    }
    int knightDialer(int n) {
        if(n==1) return 10;
        vector<int> adj[] = {{4,6}, {8,6}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}};
        vector<vector<int>> dp(n+1, vector<int>(11, -1));
        int ans = 0;
        for(int i=0;i<10;i++){
            ans += solve(n-1, i, adj, dp);
            ans %= 1000000007;
        }
        return ans;
    }
};

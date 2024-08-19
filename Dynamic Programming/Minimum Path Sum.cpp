// Tabulation Solution
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> dp(r, vector<int> (c, 0));
        dp[0][0] = grid[0][0];
        for(int i=1;i<r;i++) dp[i][0] = grid[i][0] + dp[i-1][0];
        for(int j=1;j<c;j++) dp[0][j] = grid[0][j] + dp[0][j-1];
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[r-1][c-1];
    }
};


// Memoization Solution
class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>> &dp){
        if(i==m-1 && j==n-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==m-1) return dp[i][j] = solve(grid, i, j+1, m, n, dp) + grid[i][j];
        if(j==n-1) return dp[i][j] = solve(grid, i+1, j, m, n, dp) + grid[i][j];
        return dp[i][j] = min(solve(grid, i, j+1, m, n, dp), solve(grid, i+1, j, m, n, dp)) + grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solve(grid, 0, 0, m, n, dp);
    }
};

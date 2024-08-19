// Tabulation Solution
class Solution {
public:
    int countSquares(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> dp(r, vector<int> (c, 0));
        int total = 0;
        for(int i=0;i<r;i++) {
            int num = grid[i][0];
            dp[i][0] = num;
        }
        for(int j=0;j<c;j++){
            int num = grid[0][j];
            dp[0][j] = num;
        }
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                int num = grid[i][j];
                if(num){
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                total += dp[i][j];
            }
        }
        return total;
    }
};

// Memoization Solution
class Solution {
public:
    int solve(vector<vector<int>>& matrix, int i, int j, vector<vector<int>> &dp){
        if(i==matrix.size() || j==matrix[0].size() || matrix[i][j]==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int right = solve(matrix, i, j+1, dp);
        int down = solve(matrix, i+1, j, dp);
        int diag = solve(matrix, i+1, j+1, dp);

        return dp[i][j] = 1 + min({right, down, diag});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> dp(r, vector<int>(c, -1));
        int total = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                total += solve(matrix, i, j, dp);
            }
        }
        return total;
    }
};

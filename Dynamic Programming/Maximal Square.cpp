// Tabulation Solution
class Solution {
public:
    int maximalSquare(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> dp(r, vector<int> (c, 0));
        int maxi = 0;
        for(int i=0;i<r;i++) {
            int num = grid[i][0]-48;
            dp[i][0] = num;
            maxi = max(maxi, dp[i][0]);
        }
        for(int j=0;j<c;j++){
            int num = grid[0][j]-48;
            dp[0][j] = num;
            maxi = max(maxi, dp[0][j]);
        }
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                int num = grid[i][j]-48;
                if(num){
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                    maxi = max(maxi, dp[i][j]);
                }
            }
        }
        return maxi*maxi;
    }
};

// Memoization Solution
class Solution {
public:
    int helper(vector<vector<char>>& mat, int i, int j, int &ans, vector<vector<int>> &dp){
        if(i>=mat.size() || j>=mat[0].size()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int right = helper(mat, i, j+1, ans, dp);
        int bottom = helper(mat, i+1, j, ans, dp);
        int diag = helper(mat, i+1, j+1, ans, dp);

        if(mat[i][j]=='1'){
            dp[i][j] = 1+min(right, min(bottom, diag));
            ans = max(dp[i][j], ans);
            return dp[i][j];
        }
        else return dp[i][j] = 0;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> dp(r, vector<int> (c, -1));
        helper(matrix, 0, 0, ans, dp);
        return ans*ans;
    }
};

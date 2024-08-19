// Tabulation Solution
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        int maxi = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    maxi = max(maxi, dp[i][j]);
                }
            }
        }
        return maxi;
    }
};

// Memoization Solution
class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>> &dp){
        // Base Case
        if(i==-1 || j==-1) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        if(nums1[i]==nums2[j]) dp[i][j] = solve(nums1, nums2, i-1, j-1, dp) + 1;
        else dp[i][j] = 0;
        return dp[i][j];
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxi = max(maxi, solve(nums1, nums2, i, j, dp));
            }
        }
        return maxi;
    }
};

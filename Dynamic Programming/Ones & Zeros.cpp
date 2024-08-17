// Tabulation Approach
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s = strs.size();
        vector<vector<vector<int>>> dp(s+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        for(int i=1;i<=s;i++){
            int zeros = count(strs[i-1].begin(), strs[i-1].end(), '0');
            int ones = strs[i-1].size()-zeros;
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    if(j-zeros>=0 && k-ones>=0){
                        int l = dp[i-1][j-zeros][k-ones];
                        int r = dp[i-1][j][k];
                        dp[i][j][k] = max(l+1, r);
                    }
                    else dp[i][j][k] = dp[i-1][j][k];
                }
            }
        }
        return dp[s][m][n];
    }
};


// Memoization Approach
class Solution {
public:
    int helper(vector<pair<int, int>> &arr, int idx, int m, int n, vector<vector<vector<int>>> &dp){
        if(idx==-1) return 0;
        if(m==0 && n==0) return 0;
        if(dp[idx][m][n]!=-1) return dp[idx][m][n];
        int a = m-arr[idx].first;
        int b = n-arr[idx].second;
        if(a>=0 && b>=0){
            int l = helper(arr, idx-1, a, b, dp)+1;
            int r = helper(arr, idx-1, m, n, dp);
            return dp[idx][m][n] = max(l, r);
        }
        return dp[idx][m][n] = helper(arr, idx-1, m, n, dp);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> arr;
        int s = strs.size();
        for(int i=0;i<s;i++){
            int o = 0;
            int z = 0;
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]=='0') z++;
                else o++;
            }
            arr.push_back({z, o});
        }
        vector<vector<vector<int>>> dp(s+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return helper(arr, strs.size()-1, m, n, dp);
    }
};

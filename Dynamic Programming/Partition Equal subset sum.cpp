class Solution{
public:
    bool solve(int idx, long long curr, long long &total, int arr[], vector<vector<int>> &dp){
        if(idx==-1) return false;
        if(dp[idx][curr]!=-1) return dp[idx][curr];
        if(total-curr==curr) return true;
        return dp[idx][curr] = solve(idx-1, curr+arr[idx], total, arr, dp) ||
        solve(idx-1, curr, total, arr, dp);
    }
    int equalPartition(int N, int arr[])
    {
        long long total = 0;
        for(int i=0;i<N;i++){
            total += arr[i];
        }
        vector<vector<int>> dp(N, vector<int> (total+1, -1));
        return solve(N-1, 0, total, arr, dp);
    }
};

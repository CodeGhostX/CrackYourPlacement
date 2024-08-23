class Solution {
public:
    int solve(int idx, vector<int>& stones, int jump, int &n, vector<vector<int>> &dp){
        if(idx==n-1) return true;
        if(dp[idx][jump]!=-1) return dp[idx][jump];
        int i = idx;
        bool a = false;
        while(i<n && (stones[idx]+jump+1)>=stones[i]){
            if(stones[idx]+jump+1==stones[i]){
                a = a || solve(i, stones, jump+1, n, dp);
            }
            i++;
        }
        i = idx;
        while(i<n && (stones[idx]+jump)>=stones[i]){
            if(stones[idx]+jump==stones[i]){
                a = a || solve(i, stones, jump, n, dp);
            }
            i++;
        }
        i = idx+1;
        while(i<n && (stones[idx]+jump-1)>=stones[i]){
            if(stones[idx]+jump-1==stones[i]){
                a = a || solve(i, stones, jump-1, n, dp);
            }
            i++;
        }
        return dp[idx][jump] = a;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1]>1) return false;
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(2002, -1));
        return solve(1, stones, 1, n, dp);
    }
};

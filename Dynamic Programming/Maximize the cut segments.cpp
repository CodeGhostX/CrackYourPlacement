// Tabulation
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1, 0);
        for(int i=1;i<=n;i++){
            int one, two, three;
            
            if(i-x<0) one = INT_MIN;
            else one = dp[i-x]+1;
            
            if(i-y<0) two = INT_MIN;
            else two = dp[i-y]+1;
            
            if(i-z<0) three = INT_MIN;
            else three = dp[i-z]+1;
            
            dp[i] = max({one, two, three});
        }
        if(dp[n]<0) return 0;
        return dp[n];
    }
};

// Memoization
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int solve(int n, int x, int y, int z, vector<int> &dp){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int one = INT_MIN, two = INT_MIN, three = INT_MIN;
        if(n-x>=0){
            one = 1 + solve(n-x, x, y, z, dp);
        }
        if(n-y>=0){
            two = 1 + solve(n-y, x, y, z, dp);
        }
        if(n-z>=0){
            three = 1 + solve(n-z, x, y, z, dp);
        }
        return dp[n] = max({one, two, three});
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1, -1);
        int m = solve(n, x, y, z, dp);
        if(m<0) return 0;
        return m;
    }
};

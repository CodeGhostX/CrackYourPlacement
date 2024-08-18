class Solution {
public:
    int solve(int i, string &s, vector<int> &dp){
        if(s[i]=='0') return 0;
        if(i==s.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        int ans = 0;
        if(i!=s.size()-1){
            int n2 = s[i]-48;
            n2 = n2*10 + (s[i+1]-48);
            if(n2>=1 && n2<=26) ans += solve(i+2, s, dp);
        }
        ans += solve(i+1, s, dp);
        return dp[i] = ans;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        return solve(0, s, dp);
    }
};

# define mod 1000000007
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            int el = arr[i];
            while(!st.empty() && arr[st.top()]>el) {
                int idx = st.top();
                int item = arr[idx];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int a = idx-left;
                int b = i-idx;
                ans = (ans + (a*b*1LL*item)%mod)%mod;
            }
            st.push(i);
        }
        int i = n;
        while(!st.empty()){
            int idx = st.top();
            int item = arr[idx];
            st.pop();
            int left = st.empty() ? -1 : st.top();
            int a = idx-left;
            int b = i-idx;
            ans = (ans + (a*b*1LL*item)%mod)%mod;
        }
        return ans;
    }
};

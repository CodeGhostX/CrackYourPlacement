#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int el = heights[st.top()];
                st.pop();
                int left = st.empty() ? -1: st.top();
                int curr = el*(i-left-1);
                ans = max(ans, curr);
            }
            st.push(i);
        }
        int i = n;
        while(!st.empty()){
            int el = heights[st.top()];
            st.pop();
            int left = st.empty() ? -1: st.top();
            int curr = el*(i-left-1);
            ans = max(ans, curr);
        }
        return ans;
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int maxRectangle(vector<int> &arr){
        stack<int> st;
        int ans = INT_MIN;
        for(int i=0;i<arr.size();i++){
            int el = arr[i];
            while(!st.empty() && arr[st.top()]>el){
                int e = arr[st.top()];
                st.pop();
                int left;
                if(st.empty()) left = -1;
                else left = st.top();
                int curr = e*(i-left-1);
                ans = max(ans, curr);
            }
            st.push(i);
        }
        int i = arr.size();
        while(!st.empty()){
            int el = arr[st.top()];
            st.pop();
            int left;
            if(st.empty()) left = -1;
            else left = st.top();
            int curr = el*(i-left-1);
            ans = max(ans, curr);
        }
        return ans;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        vector<int> arr(m);
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]==0) arr[j] = 0;
                else arr[j]++;
            }
            ans = max(ans, maxRectangle(arr));
        }
        return ans;
    }
};
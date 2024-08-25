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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int c = matrix[0].size();
        vector<int> temp(c, 0);
        int ans = 0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    temp[j] += 1;
                }
                else temp[j] = 0;
            }
            ans = max(ans, largestRectangleArea(temp));
        }
        return ans;
    }
};

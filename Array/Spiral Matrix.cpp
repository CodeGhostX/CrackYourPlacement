#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int top = 0;
        int down = r-1;
        int left = 0;
        int right = c-1;
        int done = 0;
        vector<int> ans;
        while(done<r*c){
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
                done++;
            }
            if(done==r*c) break;
            top++;
            for(int i=top;i<=down;i++){
                ans.push_back(matrix[i][right]);
                done++;
            }
            if(done==r*c) break;
            right--;
            for(int i=right;i>=left;i--){
                ans.push_back(matrix[down][i]);
                done++;
            }
            if(done==r*c) break;
            down--;
            for(int i=down;i>=top;i--){
                ans.push_back(matrix[i][left]);
                done++;
            }
            if(done==r*c) break;
            left++;
        }
        return ans;
    }
};
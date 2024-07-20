#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void DFS(vector<vector<char>>& grid, vector<vector<int>> &ans, int i, int j){
        int r = grid.size();
        int c = grid[0].size();
        if(i>=r || j>=c || j<0 || i<0 || ans[i][j] || grid[i][j]=='0'){
            return;
        }
        ans[i][j] = 1;
        DFS(grid, ans, i+1, j);
        DFS(grid, ans, i, j-1);
        DFS(grid, ans, i-1, j);
        DFS(grid, ans, i, j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> ans(r, vector<int>(c, 0));
        int count = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1' && ans[i][j]==0){
                    DFS(grid, ans, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
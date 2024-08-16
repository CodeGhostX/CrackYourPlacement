class Solution {
public:
    void DFS(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j){
        int r = grid.size();
        int c = grid[0].size();
        if(i==r || j==c || i<0 || j<0 || vis[i][j] || grid[i][j]=='0') return;
        vis[i][j] = 1;
        DFS(grid, vis, i+1, j);
        DFS(grid, vis, i, j+1);
        DFS(grid, vis, i-1, j);
        DFS(grid, vis, i, j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> vis(r, vector<int> (c, 0));
        int count = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    count++;
                    DFS(grid, vis, i, j);
                }
            }
        }
        return count;
    }
};

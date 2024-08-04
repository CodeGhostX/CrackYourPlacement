class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int r = grid.size();
        int c = grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2) q.push({i, j});
            }
        }
        int d = -1;
        while(!q.empty()){
            d++;
            int n = q.size();
            for(int i=0;i<n;i++){
                auto f = q.front();
                q.pop();
                int dx[] = {-1, 0, 1, 0};
                int dy[] = {0, 1, 0, -1};
                for(int k=0;k<4;k++){
                    int nx = f.first+dx[k];
                    int ny = f.second+dy[k];
                    if(nx>=0 && ny>=0 && nx<r && ny<c && grid[nx][ny]==1){
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        if(d==-1) return 0;
        return d;
    }
};

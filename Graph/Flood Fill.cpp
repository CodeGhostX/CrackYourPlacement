class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int, int>> q;
        int st_clr = image[sr][sc];
        int r = image.size();
        int c = image[0].size();
        q.push({sr, sc});
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        int count = 0;
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            image[i][j] = color;
            q.pop();
            for(int k=0;k<4;k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(ny>=0 && nx>=0 && nx<r && ny<c && image[nx][ny]==st_clr && image[nx][ny]!=color){
                    q.push({nx, ny});
                }
            }
        }
        return image;
    }
};

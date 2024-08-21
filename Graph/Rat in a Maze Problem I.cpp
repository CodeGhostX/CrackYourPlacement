class Solution {
  public:
    void solve(int i, int j, vector<vector<int>> &mat, vector<string> &ans, string temp){
        int r = mat.size();
        int c = mat[0].size();
        if(i==r || j==c || i<0 || j<0 || mat[i][j]!=1){
            return;
        }
        int curr = mat[i][j];
        mat[i][j] = -1;
        if(i==r-1 && j==c-1) ans.push_back(temp);
        solve(i+1, j, mat, ans, temp+"D");
        solve(i-1, j, mat, ans, temp+"U");
        solve(i, j+1, mat, ans, temp+"R");
        solve(i, j-1, mat, ans, temp+"L");
        mat[i][j] = curr;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> ans;
        solve(0, 0, mat, ans, "");
        return ans;
    }
};

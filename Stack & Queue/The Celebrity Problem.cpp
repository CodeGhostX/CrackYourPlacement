class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        for(int i=0;i<n;i++){
            int zero_count = 0;
            for(int j=0;j<n;j++){
                if(mat[i][j]==0)
                zero_count++;
            }
            if(zero_count==n){
                int ones = 0;
                for(int k=0;k<n;k++){
                    if(mat[k][i]==1) ones++;
                }
                if(ones==n-1) return i;
            }
        }
        return -1;
    }
};

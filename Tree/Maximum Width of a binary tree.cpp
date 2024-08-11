class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int maxi = 0;
        while(!q.empty()){
            int n = q.size();
            int d = q.back().second - q.front().second + 1;
            maxi = max(maxi, d);
            for(int i=0;i<n;i++){
                auto f = q.front();
                q.pop();
                TreeNode* temp = f.first;
                int idx = f.second;
                if(temp->left){
                    long long left_idx = idx*1ll*2+1;
                    q.push({temp->left, left_idx});
                }
                if(temp->right){
                    long long right_idx = idx*1ll*2+2;
                    q.push({temp->right, right_idx});
                }
            }
        }
        return maxi;
    }
};

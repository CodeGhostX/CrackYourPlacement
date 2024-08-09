class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        int idx = 1;
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            int n = q.size();
            vector<int> arr;
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                arr.push_back(temp->val);
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(idx%2==0) reverse(arr.begin(), arr.end());
            ans.push_back(arr);
            idx++;
        }
        return ans;
    }
};

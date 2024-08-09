class Solution {
public:
    void inorder(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
        if(!root) return;
        inorder(root->left, parent);
        parent[root->left] = root;
        parent[root->right] = root;
        inorder(root->right, parent);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<TreeNode*, int> visited;
        for(auto it: parent){
            visited[it.first] = 0;
        }
        inorder(root, parent);
        queue<TreeNode*> q;
        q.push(target);
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            vector<int> ans;
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                if(level==k && !visited[temp]) {
                    ans.push_back(temp->val);
                }
                visited[temp] = 1;
                q.pop();
                if(temp->left && !visited[temp->left] ) q.push(temp->left);
                if(temp->right && !visited[temp->right]) q.push(temp->right);
                if(parent[temp] && !visited[parent[temp]]) q.push(parent[temp]);
            }
            if(level==k) {
                return ans;
            }
            level++;
        }
        return {};
    }
};

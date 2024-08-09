class Solution {
public:
    void inorder(TreeNode* root, vector<int> &ans){
        if(!root) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    void sorting(vector<int> &arr){
        int n = arr.size();
        int f = -1;
        int s = -1;
        for(int i=1;i<n;i++){
            if(arr[i-1] > arr[i]){
                if(f==-1) f = i-1;
                else s = i;
            }
        }
        if(s!=-1) swap(arr[f], arr[s]);
        else swap(arr[f], arr[f+1]);
    }
    void changeValue(TreeNode* root, int &idx, vector<int> &ans){
        if(!root) return;
        changeValue(root->left, idx, ans);
        root->val = ans[idx];
        idx++;
        changeValue(root->right, idx, ans);
    }
    void recoverTree(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        sorting(ans);
        int i = 0;
        changeValue(root, i, ans);
    }
};

class Solution {
public:
    void inorder(TreeNode* root, int &k, int &ans){
        if(!root) return;
        inorder(root->left, k, ans);
        k--;
        if(k==0){
            ans = root->val;
        }
        inorder(root->right,k, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        inorder(root, k, ans);
        return ans;
    }
};

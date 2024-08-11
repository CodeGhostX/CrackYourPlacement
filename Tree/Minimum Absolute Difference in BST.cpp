class Solution {
public:
    int minDiff = INT_MAX;
    TreeNode* prev = NULL;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(prev)
        minDiff = min(minDiff, abs(root->val - prev->val));
        prev = root;
        inorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return minDiff;
    }
};

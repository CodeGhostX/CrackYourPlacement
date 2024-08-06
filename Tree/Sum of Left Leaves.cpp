class Solution {
public:
    void inorder(TreeNode* root, int d, int &total){
        if(!root) return;
        if(d && !root->left && !root->right) total += root->val;
        inorder(root->left, 1, total);
        inorder(root->right, 0, total);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int total = 0;
        inorder(root, 0, total);
        return total;
    }
};

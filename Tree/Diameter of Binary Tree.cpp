class Solution {
public:
    int height(TreeNode* root, int &d){
        if(!root) return 0;
        int l = height(root->left, d); 
        int r = height(root->right, d); 
        d = max(d, l+r);
        return max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        height(root, d);
        return d;
    }
};

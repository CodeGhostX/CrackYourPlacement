class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int d = 0;
        if(!root) return d;
        if(root->val>= low && root->val<=high){
            d = root->val;
        }
        return d + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};

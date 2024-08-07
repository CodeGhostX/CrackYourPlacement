class Solution {
public:
    bool check(TreeNode* root, int target, int curr){
        if(!root) return false;
        curr += root->val;
        if(!root->left && !root->right) return curr==target;
        return check(root->left, target, curr) || check(root->right, target, curr);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false; 
        return check(root, targetSum, 0);
    }
};

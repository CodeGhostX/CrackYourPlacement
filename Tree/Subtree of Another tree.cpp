class Solution {
public:
    bool isEqual(TreeNode* root1, TreeNode* root2){
        if(!root1 && root2) return false;
        else if(root1 && !root2) return false;
        else if(!root1 && !root2) return true;
        if(root1->val!=root2->val) return false;
        return isEqual(root1->left, root2->left) && isEqual(root1->right, root2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(root->val==subRoot->val && isEqual(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot); 
    }
};

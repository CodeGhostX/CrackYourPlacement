class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return NULL;
        else if(root1 && !root2) return root1;
        else if(!root1 && root2) return root2;
        TreeNode* temp = new TreeNode(root1->val + root2->val);
        temp->left = mergeTrees(root1->left, root2->left);
        temp->right = mergeTrees(root1->right, root2->right);
        return temp;
    }
};

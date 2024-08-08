class Solution {
public:
    void preorder(TreeNode* root, vector<TreeNode*> &arr){
        if(!root) return;
        arr.push_back(root);
        preorder(root->left, arr);
        preorder(root->right, arr);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> arr;
        preorder(root, arr);
        arr.push_back(NULL);
        for(int i=0;i<arr.size()-1;i++){
            arr[i]->right = arr[i+1];
            arr[i]->left = NULL;
        }
    }
};

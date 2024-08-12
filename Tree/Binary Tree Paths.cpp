class Solution {
public:
    void preorder(TreeNode* root, vector<string>& ans, string temp){
        if(!root) return;
        temp += "->" + to_string(root->val);
        if(!root->left && !root->right){
            ans.push_back(temp.substr(2));
        }
        preorder(root->left, ans, temp);
        preorder(root->right, ans, temp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        preorder(root, ans, "");
        return ans;
    }
};

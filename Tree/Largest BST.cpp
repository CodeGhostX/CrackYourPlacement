class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    void inorder(Node* root, vector<int> & ans){
        if(!root) return;
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
    int isBST(Node* root){
        if(!root) return true;
        vector<int> ans;
        inorder(root, ans);
        int a = ans.size();
        for(int i=1;i<ans.size();i++){
            if(ans[i]<=ans[i-1]) return -1;
        }
        return a;
    }
    void preorder(Node* root, int &ans){
        if(!root) return;
        int a = isBST(root);
        if(a!=-1 && a>ans) ans = a;
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
    int largestBst(Node *root)
    {
    	int ans = 1;
    	preorder(root, ans);
    	return ans;
    }
};

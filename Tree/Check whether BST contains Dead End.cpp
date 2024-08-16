class Solution{
  public:
    bool checkDead(Node* root, int left, int right){
        if(!root) return false;
        if(root->data-1 == left && root->data+1 == right) return true;
        return checkDead(root->right, root->data, right) || 
        checkDead(root->left, left, root->data);
    }
    bool isDeadEnd(Node *root)
    {
        return checkDead(root, 0, INT_MAX);
    }
};

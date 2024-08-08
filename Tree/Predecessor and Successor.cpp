class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        if(!root) return;
        if(root->key==key){
            Node* temp = root->left;
            while(temp && temp->right) temp = temp->right;
            if(temp) pre = temp;
            
            temp = root->right;
            while(temp && temp->left) temp = temp->left;
            if(temp) suc = temp;
            return;
        }
        else if(root->key>key){
            suc = root;
            findPreSuc(root->left, pre, suc, key);
        }
        else {
            pre = root;
            findPreSuc(root->right, pre, suc, key);
        }
    }
};

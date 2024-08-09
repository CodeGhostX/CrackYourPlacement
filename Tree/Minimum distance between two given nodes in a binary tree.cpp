class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    void inorder(Node* root, string temp, string &first, string &second, int a, int b){
        if(!root) return;
        if(root->data==a) first = temp;
        if(root->data==b) second = temp;
        inorder(root->left, temp + "L", first, second, a, b);
        inorder(root->right, temp + "R", first, second, a, b);
    }
    int findDist(Node* root, int a, int b) {
        string first;
        string second;
        inorder(root, "", first, second, a, b);
        int i = 0;
        while(i<first.size() && i<second.size() && first[i]==second[i]) i++;
        int ans = 0;
        ans += first.size()-i;
        ans += second.size()-i;
        return ans;
    }
};

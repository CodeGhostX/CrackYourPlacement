class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    struct TrieNode{
        bool isEnd;
        TrieNode* children[26];
    };
    TrieNode* getNode(){
        TrieNode* temp = new TrieNode();
        temp->isEnd = false;
        for(int i=0;i<26;i++){
            temp->children[i] = NULL;
        }
        return temp;
    }
    void insert(string word, TrieNode* root){
        TrieNode* temp = root;
        for(int i=0;i<word.size();i++){
            if(!temp->children[word[i]-'a'])
            temp->children[word[i]-'a'] = getNode();
            temp = temp->children[word[i]-'a'];
        }
        temp->isEnd = true;
    }
    bool searchWord(TrieNode* root, string &word, int st, TrieNode* &ultimate){
        
        TrieNode* temp = root;
        
        for(int i=st;i<word.size();i++){
            if(temp->isEnd && searchWord(ultimate, word, i, ultimate)) return true;
            if(temp->children[word[i]-'a']){
                temp = temp->children[word[i]-'a'];
            }
            else return false;
        }
        return temp->isEnd;
    }
    int wordBreak(string A, vector<string> &B) {
        TrieNode* root = getNode();
        for(int i=0;i<B.size();i++){
            insert(B[i], root);
        }
        return searchWord(root, A, 0, root);
    }
};

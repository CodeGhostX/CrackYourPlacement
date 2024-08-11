class Trie {
public:
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
    TrieNode* root;
    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(int i=0;i<word.size();i++){
            if(!temp->children[word[i]-'a']){
                temp->children[word[i]-'a'] = getNode();
            }
            temp = temp->children[word[i]-'a'];
        }
        temp->isEnd = true;
    }
    bool searchWord(string word, int i, TrieNode* root, int f){
        if(f==1 && i==word.size()) return root->isEnd;
        else if(f==2 && i==word.size()) return true;
        if(root->children[word[i]-'a'])  return searchWord(word,i+1,root->children[word[i]-'a'],f);
        else return false;
    }
    bool search(string word) {
        return searchWord(word, 0, root, 1);
    }
    
    bool startsWith(string prefix) {
        return searchWord(prefix, 0, root, 2);
    }
};

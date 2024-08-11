class WordDictionary {
public:
    struct TrieNode{
        bool isEnd;
        TrieNode* children[26];
    };
    TrieNode* getNode(){
        TrieNode* temp = new TrieNode();
        temp->isEnd = false;
        for(int i=0;i<26;i++) temp->children[i] = NULL;
        return temp;
    }
    TrieNode* root;
    WordDictionary() {
        root = getNode();
    }
    
    void addWord(string word) {
        TrieNode* temp = root;
        for(int i=0;i<word.size();i++){
            if(!temp->children[word[i]-'a']){
                temp->children[word[i]-'a'] = getNode();
            }
            temp = temp->children[word[i]-'a'];
        }
        temp->isEnd = true;
    }
    bool searchWord(TrieNode* root, int i, string &word){
        if(i==word.size()) return root->isEnd;
        if(word[i]=='.'){
            for(int j=0;j<26;j++){
                if(root->children[j]){
                    if(searchWord(root->children[j], i+1, word)) return true;
                }
            }
            return false;
        }
        else if(root->children[word[i]-'a']){
            return searchWord(root->children[word[i]-'a'], i+1, word);
        }
        else{
            return false;
        }
    }
    bool search(string word) {
        return searchWord(root, 0, word);
    }
};

class Solution{
public:
    struct TrieNode{
        set<string> arr;
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
            if(!temp->children[word[i]-'a']){
                temp->children[word[i]-'a'] = getNode();
            }
            temp = temp->children[word[i]-'a'];
            temp->arr.insert(word);
        }
        temp->isEnd = true;
    }
    void searchWord(vector<vector<string>> &ans, string word, int st, TrieNode* root){
        TrieNode* temp = root;
        for(int i=st;i<word.size();i++){
            if(temp && temp->children[word[i]-'a']){
                temp = temp->children[word[i]-'a'];
                vector<string> main(temp->arr.begin(), temp->arr.end());
                ans.push_back(main);
            }
            else {
                temp = NULL;
                ans.push_back({"0"});
            }
        }
    }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>> ans;
        TrieNode* root = getNode();
        for(int i=0;i<n;i++){
            insert(contact[i], root);
        }
        searchWord(ans, s, 0, root);
        return ans;
    }
};

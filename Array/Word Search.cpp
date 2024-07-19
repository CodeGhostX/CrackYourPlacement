#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool DFS(vector<vector<char>>& board, string &word, int i, int j, int idx){
        int r = board.size();
        int c = board[0].size();
        if(i>=r || j>=c || i<0 || j<0 || board[i][j]=='0' || word[idx]!=board[i][j]) return false;
        char a = board[i][j];
        board[i][j] = '0';
        if(idx==word.size()-1 && word[idx]==a) return true;
        bool l = DFS(board, word, i-1, j, idx+1);
        bool rt = DFS(board, word, i+1, j, idx+1);
        bool u = DFS(board, word, i, j-1, idx+1);
        bool d = DFS(board, word, i, j+1, idx+1);
        board[i][j] = a;
        return l || rt || u || d;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(word[0]==board[i][j]) {
                    if(DFS(board, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};
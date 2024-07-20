#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> dx = {-1, -1, 0, 1, 1, 1, 0, -1};
        vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1};
        int r = board.size();
        int c = board[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int count = 0;
                for(int k=0;k<8;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx>=0 && nx<r && ny<c && ny>=0 && abs(board[nx][ny])==1){
                        count++;
                    }
                }
                if(board[i][j]==1){
                    if(count>3 || count<2){
                        board[i][j] = -1;
                    }
                }
                else if(board[i][j]==0){
                    if(count==3)
                    board[i][j] = 2;
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]==-1) board[i][j] = 0;
                else if(board[i][j]==2) board[i][j] = 1;
            }
        }
    }
};
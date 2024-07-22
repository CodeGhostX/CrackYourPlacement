#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
void DFS(vector<vector<int>> &vis, int i, int j, char** arr, int n, int m){
    if(i<0 || j<0 || i>=n || j>=m || arr[i][j]=='X' || vis[i][j]){
        return;
    }
    vis[i][j] = 1;
    DFS(vis, i+1, j, arr, n, m);
    DFS(vis, i, j+1, arr, n, m);
    DFS(vis, i-1, j, arr, n, m);
    DFS(vis, i, j-1, arr, n, m);
}

void replaceOWithX(char** arr, int n, int  m)
{
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j==0 || i==n-1 || j==m-1){
                if(vis[i][j]==0) DFS(vis, i, j, arr, n, m);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0){
                arr[i][j] = 'X';
            }
        }
    }
}
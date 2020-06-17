// Problem

// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.


// Example

// Input: 
// X X X X
// X O O X
// X X O X
// X O X X

// Output: 
// X X X X
// X X X X
// X X X X
// X O X X


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void bfs(vector<vector<char>>& board,int i,int j,int n,int m){
        vector<vector<int>> moves ({{1,0},{0,1},{-1,0},{0,-1}});
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m));
        q.push({i,j});
        vis[i][j]=1;
        board[i][j]='O';
        auto chk = [&](int a,int b){return a>=0&&a<n&&b>=0&&b<m;};
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(auto mv : moves){
                pair<int,int> n_crd = {curr.first+mv[0],curr.second+mv[1]};
                if(chk(n_crd.first,n_crd.second)&&vis[n_crd.first][n_crd.second]==0&&board[n_crd.first][n_crd.second]=='T'){
                    vis[n_crd.first][n_crd.second] = 1;
                    q.push(n_crd);
                    board[n_crd.first][n_crd.second]='O';
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        if(!board.empty())
        {
            int n = board.size();
            int m = board[0].size();
            for(int i=0;i<n;i++)for(int j=0;j<m;j++)
                if(board[i][j]=='O')board[i][j]='T';
            for(int i=0;i<n;i++){
                if(board[i][0]=='T')
                    bfs(board,i,0,n,m);
                if(board[i][m-1]=='T')
                    bfs(board,i,m-1,n,m);
            }
            for(int i=0;i<m;i++){
                if(board[0][i]=='T')
                    bfs(board,0,i,n,m);
                if(board[n-1][i]=='T')
                    bfs(board,n-1,i,n,m);
            }
            for(int i=0;i<n;i++)for(int j=0;j<m;j++)
                if(board[i][j]=='T')board[i][j]='X';
        }
    }
};
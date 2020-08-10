// Problem

// In a given grid, each cell can have one of three values:

// the value 0 representing an empty cell;
// the value 1 representing a fresh orange;
// the value 2 representing a rotten orange.
// Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.



// Example

// Input: [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4

// Input: [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1

// Input: [[0,2]]
// Output: 0



// Constraints:

// 1 <= grid.length <= 10
// 1 <= grid[0].length <= 10
// grid[i][j] is only 0, 1, or 2.


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        int ans = -1;
        while(!q.empty()){
            int x = q.size();
            ans++;
            while(x--){
                auto curr = q.front();
                q.pop();
                for(auto d : dir){
                    int n_i = curr.first+d[0];
                    int n_j = curr.second+d[1];
                    if(n_j>=0&&n_j<m&&n_i>=0&&n_i<n&&grid[n_i][n_j]==1){
                        grid[n_i][n_j]=2;
                        q.push({n_i,n_j});
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==1) return -1;
        return max(ans,0);
    }
};
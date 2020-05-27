// Problem

// Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.
// Each person may dislike some other people, and they should not go into the same group. 
// Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.
// Return true if and only if it is possible to split everyone into two groups in this way



// Example

// Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
// Output: true

// Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
// Output: false


// Constraints:

// 1 <= N <= 2000
// 0 <= dislikes.length <= 10000
// 1 <= dislikes[i][j] <= N
// dislikes[i][0] < dislikes[i][1]
// There does not exist i != j for which dislikes[i] == dislikes[j].

//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> vis(N);
        vector<vector<int>> grp(N);
        for(auto p : dislikes){
            grp[p[0]-1].push_back(p[1]-1);
            grp[p[1]-1].push_back(p[0]-1);
        }
        queue<int> q;
        for(auto p : dislikes)
        {
            if(vis[p[0]-1]!=0)continue;
            q.push(p[0]-1);
            vis[p[0]-1]=1;
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                for(int i : grp[curr]){
                    if(vis[i]==0){
                        q.push(i);
                        vis[i]=vis[curr]*-1;
                    }
                    else if(vis[i]==vis[curr])return false;
                }
            }
        }
        return true;
    }
};
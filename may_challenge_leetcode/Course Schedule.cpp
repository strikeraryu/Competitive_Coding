// Problem

// There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?



// Example

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false


// Constraints:

// The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
// You may assume that there are no duplicate edges in the input prerequisites.
// 1 <= numCourses <= 10^5

//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& prerequisites) {
        vector<vector<int>> grp(N);
        for(auto p : prerequisites){
            grp[p[0]].push_back(p[1]);
        }
        for(int i=0;i<N;i++){    
            vector<bool> vis(N);
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                for(int x : grp[curr]){
                    if(x==i)return false;
                    if(!vis[x]){
                        q.push(x);
                        vis[x]=true;
                    }
                }
            }
        }
        return true;
    }
};
// Problem

// There are a total of n courses you have to take, labeled from 0 to n-1.

// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

// Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

// There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.



// Example

// Input: 2, [[1,0]] 
// Output: [0,1]

// Input: 4, [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,1,2,3] or [0,2,1,3]


// Constraints:

// The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
// You may assume that there are no duplicate edges in the input prerequisites.

//-----------------------------------------------------------------------------------------------------
// Solution
#include <bits/stdc++.h>
using namespace std;


class Solution {
    private:
    bool dfs(vector<vector<int>>& grp, int c, vector<int> &vis, vector<int> &course_order){
        if(vis[c]==1)return true;
        if(vis[c]==2)return false;
        vis[c] = 1;
        for(const int n : grp[c])
            if(dfs(grp,n,vis,course_order))return true;
        vis[c] = 2;
        course_order.push_back(c);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int N = numCourses;
        vector<vector<int>> grp(N);
        for(const auto& p : prerequisites)
            grp[p[0]].push_back(p[1]);
        vector<int> vis(N, 0);
        vector<int> course_order;
        for(int i=0;i<N;i++)
            if(dfs(grp,i,vis,course_order))return {};
        return course_order;
    }
};
// Problem

// Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.
// The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  
// graph[i] is a list of all nodes j for which the edge (i, j) exists.

// Example

// Input: [[1,2], [3], [3], []] 
// Output: [[0,1,3],[0,2,3]] 


// Note:

// The number of nodes in the graph will be in the range [2, 15].
// You can print different paths in any order, but you should keep the order of nodes inside one path.

//-----------------------------------------------------------------------------------------------------
// Solution
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<pair<vector<int>, int>> q;
        vector<vector<int>> ans;
        q.push({{0},0});
        while(!q.empty()){
            vector<int> curr_path = q.front().first;
            int curr = q.front().second;
            cout<<curr;
            q.pop();
            if(curr == n-1)ans.push_back(curr_path);
            for(int i : graph[curr]){
                vector<int> tmp = curr_path;
                tmp.push_back(i);
                q.push({tmp,i});
            }
        }
        return ans;
    }
};
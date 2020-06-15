// Problem

// There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.
// Now given all the cities and flights, together with starting city src and the destination dst, 
// your task is to find the cheapest price from src to dst with up to k stops.If there is no such route, output -1.


// Example

// Input: 
// n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
// src = 0, dst = 2, k = 1
// Output: 200

// n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
// src = 0, dst = 2, k = 0
// Output: 500

// Constraints:

// The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
// The size of flights will be in range [0, n * (n - 1) / 2].
// The format of each flight will be (src, dst, price).
// The price of each flight will be in the range [1, 10000].
// k is in the range of [0, n - 1].
// There will not be any duplicated flights or self cycles

//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, vector<pair<int,int>>> grp;    
        for(auto p : flights)    
            grp[p[0]].push_back({p[1], p[2]});    
    
        int ans = INT_MAX;    
        queue<pair<int,int>> q;    
        q.push({src, 0});    
        int stops = 0;   
        while(!q.empty()) {    
          int size = q.size();    
          while(size--) {    
            auto curr = q.front();     
            q.pop();    
            if(curr.first == dst) ans = min(ans, curr.second);    
            for(auto p : grp[curr.first])   
              if(curr.second + p.second < ans) q.push({p.first, curr.second + p.second});       
          }    
          if(stops++ > K) break;    
        }    
        
        return ans==INT_MAX?-1:ans;
    }
};
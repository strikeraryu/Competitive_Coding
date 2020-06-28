// Problem

// Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

// Note:

// If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
// All airports are represented by three capital letters (IATA code).
// You may assume all tickets form at least one valid itinerary.
// One must use all the tickets once and only once.




// Example


// Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
// Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]


// Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
// Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]



//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> dfs(map<string,vector<pair<string,int>>> grp,vector<string> log,int max_size){
        if(log.size()==max_size)
        return log;
        string src = log.back();
        int n = grp[src].size();
        for(int i = 0;i<n;i++){
            if(grp[src][i].second == 1)continue;
            log.push_back(grp[src][i].first);
            grp[src][i].second = 1;
            auto ret = dfs(grp,log,max_size);
            log.pop_back();
            grp[src][i].second = 0;
            if(!ret.empty())return ret;
        }
        return {};
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,vector<pair<string,int>>> grp;
        for(auto t : tickets){
            grp[t[0]].push_back({t[1],0});
            sort(grp[t[0]].begin(),grp[t[0]].end());
        }
        return dfs(grp,{"JFK"},tickets.size()+1);
    }
};
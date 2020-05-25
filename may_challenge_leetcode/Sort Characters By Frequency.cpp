// Problem

// Given a string, sort it in decreasing order based on the frequency of characters.



// Example

// Input:
// "tree"
// Output:  
// "eert"

// Input:
// "Aabb"
// Output:
// "bbAa"


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mem;
        vector<pair<int,char>> cnts;
        for(char c : s){
            auto itr = mem.find(c);
            if(itr!=mem.end())cnts[itr->second].first++;
            else{
                mem[c]=cnts.size();
                cnts.push_back({1,c});
            }
        }
        sort(cnts.begin(),cnts.end(),greater<pair<int,char>>());
        string ans = "";
        for(auto i : cnts){
            for(int j=0;j<i.first;j++){
                ans+=i.second;
            }
        }
        return ans;
    }
}; 
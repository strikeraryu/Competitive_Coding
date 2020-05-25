// Problem

// In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

// If the town judge exists, then:
// The town judge trusts nobody.
// Everybody (except for the town judge) trusts the town judge.
// There is exactly one person that satisfies properties 1 and 2.
// You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

// If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.


// Example

// Input: N = 2, trust = [[1,2]]
// Output: 2

// Input: N = 3, trust = [[1,3],[2,3],[3,1]]
// Output: -1

// Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
// Output: 3


// Constraints:

// 1 <= N <= 1000
// 0 <= trust.length <= 10^4
// trust[i].length == 2
// trust[i] are all different
// trust[i][0] != trust[i][1]
// 1 <= trust[i][0], trust[i][1] <= N

//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
      vector<vector<int>> v(n+1),v2(n+1);
      for(auto t : trust){
        v[t[1]].push_back(t[0]);
        v2[t[0]].push_back(t[1]);
      }
      for(int i = 1;i<=n;i++){
        if(v[i].size()==n-1 && v2[i].size()==0)
          return i;
      }
      return -1;
    }
};
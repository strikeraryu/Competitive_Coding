// Problem

// There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], 
// and the cost of flying the i-th person to city B is costs[i][1].

// Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.


// Example

// Input: [[10,20],[30,200],[400,50],[30,20]]
// Output: 110


// Constraints:

// 1 <= costs.length <= 100
// It is guaranteed that costs.length is even.
// 1 <= costs[i][0], costs[i][1] <= 1000

//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        sort(costs.begin(), costs.end(), [&](vector<int> a,vector<int> b){
            return abs(a[0]-a[1]) > abs(b[0]-b[1]);
        });
        int a=0,b=0,ans=0;
        for(auto c : costs){
            if(a==n/2){b++;ans+=c[1];}
            else if(b==n/2){a++;ans+=c[0];}
            else{
                if(c[0]>c[1]){b++;ans+=c[1];}
                else{a++;ans+=c[0];}
            }
        }
        return ans;
    }
};
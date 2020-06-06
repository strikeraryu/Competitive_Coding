// Problem

// Given an array w of positive integers, where w[i] describes the weight of index i, 
// write a function pickIndex which randomly picks an index in proportion to its weight.


// Example

// Input: 
// ["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
// [[[1,3]],[],[],[],[],[]]
// Output: [null,0,1,1,1,0]


// Constraints:

// 1 <= w.length <= 10000
// 1 <= w[i] <= 10^5
// pickIndex will be called at most 10000 times.

//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dp;
    Solution(vector<int>& w) {
        int sum = 0;
        for(int i : w){
            sum+=i;
            dp.push_back(sum);
        }
    }
    
    int pickIndex() {
        int ch = rand()%dp.back();
        int prev = 0;
        for(int i=0;i<dp.size();i++){
            if(ch>=prev && ch<dp[i])return i;
            prev=dp[i];
        }
        return dp.back();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
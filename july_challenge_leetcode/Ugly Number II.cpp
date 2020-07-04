// Problem

// Write a program to find the n-th ugly number.

// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 



// Example

// Input: n = 10
// Output: 12


// Constraints:

// 1 is typically treated as an ugly number.
// n does not exceed 1690.


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(1690);
        int ind[3] = {0,0,0};
        dp[0] = 1;
        for(int i=1;i<n;i++){
            dp[i] = min(dp[ind[0]]*2, min(dp[ind[1]]*3, dp[ind[2]]*5));
            if(dp[i] == dp[ind[0]]*2) ind[0]++;
            if(dp[i] == dp[ind[1]]*3) ind[1]++;
            if(dp[i] == dp[ind[2]]*5) ind[2]++;
        }
        return dp[n-1];
    }
};
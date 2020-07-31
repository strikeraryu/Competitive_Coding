// Problem

// You are climbing a stair case. It takes n steps to reach to the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?



// Example

// Input: 2
// Output: 2

// Input: 3
// Output: 3



// Constraints:

// 1 <= n <= 45


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 1);
        for(int i=2;i<=n;i++)dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};
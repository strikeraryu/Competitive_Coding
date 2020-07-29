// Problem

// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
// (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
// After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)



// Example

// Input: [1,2,3,0,2]
// Output: 3 



//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2));
        int mx = 0;
        for(int i=0;i<n;i++){
            if(i==0)
                dp[i+1][0] -= prices[i];
            else{
                dp[i+1][0] = max(dp[i][0], max(mx - prices[i], dp[i-1][1] - prices[i]));
                dp[i+1][1] = dp[i][0] + prices[i];
                mx = max(mx, dp[i][1]);
            }
        }
        mx = max(mx,dp[n][1]);
        return mx;
    }
};
// Problem

// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete at most two transactions.

// Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).




// Example

// Input: prices = [3,3,5,0,0,3,1,4]
// Output: 6

// Input: prices = [1,2,3,4,5]
// Output: 4



// Constraints:

// 1 <= prices.length <= 105
// 0 <= prices[i] <= 105



//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp1(n), dp2(n);
        int mn = prices[0];
        for(int i=1;i<n;i++){
            mn = min(mn,prices[i]);
            dp1[i] = max(dp1[i-1],prices[i]-mn);
        }
        int mx = prices[n-1];
        for(int i=n-2;i>=0;i--){
            mx = max(prices[i],mx);
            dp2[i] = max(dp2[i+1],mx-prices[i]);
        }
        int ans = INT_MIN;
        for(int i=0;i<n;i++)
            ans = max(ans,dp1[i]+dp2[i]);
        return ans;
    }
};
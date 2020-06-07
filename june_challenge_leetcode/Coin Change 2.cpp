// Problem

// You are given coins of different denominations and a total amount of money. 
// Write a function to compute the number of combinations that make up that amount.
//  You may assume that you have infinite number of each kind of coin.




// Example

// Input: amount = 5, coins = [1, 2, 5]
// Output: 4


// Constraints:

// 0 <= amount <= 5000
// 1 <= coin <= 5000
// the number of coins is less than 500
// the answer is guaranteed to fit into signed 32-bit integer

//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int m = coins.size();
        if(amount==0)return 1;
        if(m==0)return 0;
        vector<vector<int>> v(amount+1,vector<int>(m));
        for(int i=0;i<m;i++)v[0][i]=1;
        for(int i=1;i<amount+1;i++){
            for(int j=0;j<m;j++){
                int a = i>=coins[j]?v[i-coins[j]][j]:0;
                int b = j>0?v[i][j-1]:0;
                v[i][j]=a+b;
            }
        }
        return v[amount][m-1];
    }
};
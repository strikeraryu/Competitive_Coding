// Problem

// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point in time. 
// The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

// How many possible unique paths are there?



// Example

// Input: m = 3, n = 2
// Output: 3

// Input: m = 7, n = 3
// Output: 28


// Constraints:

// 1 <= m, n <= 100
// It's guaranteed that the answer will be less than or equal to 2 * 10 ^ 9.


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n+1 ,vector<int>(m+1));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(j==m-1 && i==n-1)dp[i][j]=1;
                else dp[i][j] = dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};
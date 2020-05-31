// Problem

// Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
// You have the following 3 operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character



// Example

// Input: word1 = "horse", word2 = "ros"
// Output: 3

// Input: word1 = "intention", word2 = "execution"
// Output: 5


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for (int i = 0; i <= n; i++) { 
            for (int j = 0; j <= m; j++) { 
                if (i==0)dp[i][j]=j;
                else if(j==0)dp[i][j]=i;
                else if(word1[i-1]==word2[j-1])dp[i][j]=dp[i-1][j-1]; 
                else dp[i][j]=1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
            } 
        } 
    return dp[n][m];
    }
};
// Problem

// We write the integers of A and B (in the order they are given) on two separate horizontal lines.
// Now, we may draw connecting lines: a straight line connecting two numbers A[i] and B[j] such that:

// A[i] == B[j];
// The line we draw does not intersect any other connecting (non-horizontal) line.

// Note that a connecting lines cannot intersect even at the endpoints: each number can only belong to one connecting line.
// Return the maximum number of connecting lines we can draw in this way.


// Example

// Input: A = [1,4,2], B = [1,2,4]
// Output: 2

// Input: A = [2,5,1,2,5], B = [10,5,2,1,5,2]
// Output: 3


// Constraints:

// 1 <= A.length <= 500
// 1 <= B.length <= 500
// 1 <= A[i], B[i] <= 2000

//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int n = A.size(),m = B.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                dp[i][j] = max(dp[i+1][j+1],max(dp[i+1][j],dp[i][j+1]));
                if(A[i]==B[j])dp[i][j] = max(dp[i+1][j+1]+1,max(dp[i+1][j],dp[i][j+1]));
            }
        }
        return dp[0][0];
    }
};
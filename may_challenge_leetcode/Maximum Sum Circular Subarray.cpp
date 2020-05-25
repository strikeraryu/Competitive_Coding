// Problem

// Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.
// Here, a circular array means the end of the array connects to the beginning of the array.  
// (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)
// Also, a subarray may only include each element of the fixed buffer A at most once. 
//  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)



// Example

// Input: [1,-2,3,-2]
// Output: 3

// Input: [1,-2,3,-2]
// Output: 3



// Constraints:

// -30000 <= A[i] <= 30000
// 1 <= A.length <= 30000

//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int ans = INT_MIN,ans2=INT_MIN,x = 0,x2=0,n=A.size();
        bool flg = true; 
        vector<int> dp(n+1);
        for(int i=0;i<n;i++){
            x+=A[i];
            x2+=A[i];
            ans = max(ans,x);
            ans2 = max(ans2,x2);
            dp[i+1]=ans2;
            x = max(0,x);
        }
        x = 0;
        int s_max = INT_MIN;
        for(int i=n-1;i>=0;i--){
            x+=A[i];
            s_max = max(s_max,x+dp[i]);
        }
        return max(ans,s_max);
    }
};
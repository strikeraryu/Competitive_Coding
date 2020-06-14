// Problem

// Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

// Si % Sj = 0 or Sj % Si = 0.

// If there are multiple solutions, return any subset is fine.


// Example

// Input: [1,2,3]
// Output: [1,2] (of course, [1,3] will also be ok)

// Input: [1,2,4,8]
// Output: [1,2,4,8]


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.empty())return nums;
        sort(nums.begin(),nums.end());
        int n = nums.size(), max_v = 0, max_i = 0;
        vector<vector<int>> dp(n,vector<int>(2));
        for(int i=0;i<n;i++){
            dp[i]={-1,1};
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0 && dp[i][1]<dp[j][1]+1) dp[i]={j,dp[j][1]+1};
            }
            if(dp[i][1]>max_v){
                max_v = dp[i][1];
                max_i = i;
            }
        }
        vector<int> ans;
        for(int i=max_i;i!=-1;i=dp[i][0]) ans.push_back(nums[i]);
        return ans;
    }
};
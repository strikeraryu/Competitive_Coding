// Problem

// Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.


// Example

// Input: [0,1]
// Output: 2

// Input: [0,1,0]
// Output: 2


// Constraints:

// The length of the given binary array will not exceed 50,000.

//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int cnt = 0,ans = 0;
        unordered_map<int,int> dp;
        dp[0]=-1;
        for(int i = 0;i<nums.size();i++){
            cnt+=nums[i]?1:-1;
            if(dp.count(cnt)==1)ans = max(ans,i - dp[cnt]);
            else dp[cnt] = i;
        }
        return ans;
    }
};
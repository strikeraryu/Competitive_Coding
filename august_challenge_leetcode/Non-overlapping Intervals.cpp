// Problem

// Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping






// Example

// Input: [[1,2],[2,3],[3,4],[1,3]]
// Output: 1

// Input: [[1,2],[1,2],[1,2]]
// Output: 2



// Note:

// You may assume the interval's end point is always bigger than its start point.
// Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.

//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty())return 0;
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<int> dp(n);
        for(int i=0;i<n;i++){
            int mx = 1;
            for(int j=0;j<=i;j++){
                if(intervals[j][1]<=intervals[i][0]){
                    mx = max(mx,dp[j]+1);
                }
                else mx = max(mx,dp[j]);
            }
            dp[i] = mx;
        }
        return n-dp[n-1];
    }
};
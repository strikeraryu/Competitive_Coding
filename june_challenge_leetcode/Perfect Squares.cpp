// Problem

// Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.




// Example


// Input: n = 12
// Output: 3 

// Input: n = 13
// Output: 2



//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void n_sum(int cnt,int i,int tot,int &ans){
        if(tot==0)ans = min(cnt,ans);
        else if(i>=1 && cnt<ans){
            if(i*i>tot)
                n_sum(cnt,i-1,tot,ans);
            else{
                n_sum(cnt+1,i,tot-i*i,ans);
                n_sum(cnt+1,i-1,tot-i*i,ans);
                n_sum(cnt,i-1,tot,ans);
            }
        }
    }
public:
    int numSquares(int n){
        int ans = INT_MAX;
        n_sum(0,sqrt(n),n,ans);
        return ans;
    }
};
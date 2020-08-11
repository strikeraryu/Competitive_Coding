// Problem

// Given an array of citations (each citation is a non-negative integer) of a researcher, 
// write a function to compute the researcher's h-index.

// According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least 
// h citations each, and the other N − h papers have no more than h citations each."


// Example

// Input: citations = [3,0,6,1,5]
// Output: 3 

// Note:

// If there are several possible values for h, the maximum one is taken as the h-index


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        if(citations.empty())return 0;
        int n = citations.size(),ans = 0;
        int i = 0;
        for(int h=1;h<=n;h++){
            while(i<n && citations[i]<=h){
                if(citations[i]==h && n-i==h)ans=h;
                i++;
            }
            if(n-i==h)ans = h;
        }
        return ans;
    }
};
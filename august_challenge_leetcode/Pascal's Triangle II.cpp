// Problem

// Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

// Note that the row index starts from 0.


// Example

// Input: 3
// Output: [1,3,3,1]

// Note:

// Could you optimize your algorithm to use only O(k) extra space?


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans={1};
        long long int a = 1;
        for(int i=0;i<rowIndex;i++){
            a*=(rowIndex-i);
            a/=(i+1);
            ans.push_back(max(a,1ll));
        }
        return ans;
    }
};
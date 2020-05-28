// Problem

// Given a non negative integer number num. 
// For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.



// Example

// Input: 2
// Output: [0,1,1]

// Input: 5
// Output: [0,1,1,2,1,2]


// Constraints:

// It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
// Space complexity should be O(n).
// Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans{0};
        for(int i=1;i<=num;){
            for(int ind=0,n=ans.size();i<=num && ind<n;i++,ind++)
                ans.push_back(1+ans[ind]);
        }
        return ans;
    }
};
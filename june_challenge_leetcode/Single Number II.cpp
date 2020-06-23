// Problem

// Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. 
// Find that single one.

// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?






// Example

// Input: [2,2,3,2]
// Output: 3

// Input: [0,1,0,1,0,1,99]
// Output: 99



//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int b1=0,b0=0;
        for(int i : nums){
            b0 = ~b1 & (b0 ^ i);
            b1 = ~b0 & (b1 ^ i);
        }
        return b0;
    }
};
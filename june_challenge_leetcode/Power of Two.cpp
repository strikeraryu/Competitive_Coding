// Problem

// Given an integer, write a function to determine if it is a power of two.



// Example

// Input: 1
// Output: true 

// Input: 16
// Output: true


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return false;
        double pwr = log2(n);
        if(pwr-int(pwr)==0)return true;
        return false;
    }
};
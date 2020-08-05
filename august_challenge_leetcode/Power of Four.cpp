// Problem

// Given an integer (signed 32 bits),
//  write a function to check whether it is a power of 4.


// Example

// Input: 16
// Output: true

// Input: 5
// Output: false



// Follow up: Could you solve it without loops/recursion?


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 and (num & (num - 1)) == 0 and (num & 0x55555555);
    }
};
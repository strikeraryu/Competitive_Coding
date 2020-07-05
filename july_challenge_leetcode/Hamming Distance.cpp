// Problem

// The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

// Given two integers x and y, calculate the Hamming distance.



// Example

// Input: x = 1, y = 4
// Output: 2



// Constraints:

// 0 ≤ x, y < 231


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int bit = 1;
        int cnt  = 0;
        for(int i=0;i<31;i++){
            if((x&(bit<<i))!=(y&(bit<<i)))cnt++;
        }
        return cnt;
    }
};
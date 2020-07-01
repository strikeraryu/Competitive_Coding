// Problem

// You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.
// Given n, find the total number of full staircase rows that can be formed.
// n is a non-negative integer and fits within the range of a 32-bit signed integer.




// Example

// Input: 5
// Output: 2

// Input: 8
// Output: 3



//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        long long int ll_n = n;
        return (-1 + sqrt(1+8*ll_n))/2;
    }
};
// Problem

// Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

// Example

// Input: 38
// Output: 2  


// Follow up:

// Could you do it without any loop/recursion in O(1) runtime?

//-----------------------------------------------------------------------------------------------------
// Solution
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        while(num!=0){
            int n = num%10;
            num /= 10;
            sum += n;
            if(sum>=10)sum = sum%10 + 1;
        }
        if(sum>=10)sum = sum%10 + 1;
        return sum;
    }
};
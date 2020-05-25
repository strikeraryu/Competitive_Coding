// Problem

// Given a positive integer num, output its complement number. 
// The complement strategy is to flip the bits of its binary representation.


// Example

// Input: num = 5
// Output: 2

// Input: num = 1
// Output: 0



// Constraints:

//The given integer num is guaranteed to fit within the range of a 32-bit signed integer.
// num >= 1
// You could assume no leading zero bit in the integer’s binary representation.


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
      int ret=0,bit = 1;
      while(num){
        if(num%2==0)
          ret = ret | bit;
        bit = bit<<1;
        num = num>>1;
      }
      return ret;
    }
};
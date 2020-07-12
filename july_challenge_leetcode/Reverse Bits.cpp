// Problem

// Reverse bits of a given 32 bits unsigned integer.

// Note that in some languages such as Java, there is no unsigned integer type. In this case, both input and output will be given as signed integer type and should not affect your implementation, as the internal binary representation of the integer is the same whether it is signed or unsigned.
// In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above the input represents the signed integer -3 and the output represents the signed integer -1073741825.
 

// Follow up:

// If this function is called many times, how would you optimize it?



// Example

// Input: 11111111111111111111111111111101
// Output: 10111111111111111111111111111111

// Input: 00000010100101000001111010011100
// Output: 00111001011110000010100101000000


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        long long int bit = 1;
        uint32_t ans = 0;
        for(int i=0;i<32;i++){
            if((n&(bit<<i))==(bit<<i))ans = ans|(bit<<(31-i));
        }
        return ans;
    }
};
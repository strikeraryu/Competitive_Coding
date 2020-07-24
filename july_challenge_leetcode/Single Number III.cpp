// Problem

// Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice.
//  Find the two elements that appear only once.

// Example

// Input:  [1,2,1,3,2,5]
// Output: [3,5]


// Note:

// The order of the result is not important. So in the above example, [5, 3] is also correct.
// Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

//-----------------------------------------------------------------------------------------------------
// Solution
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans = {0,0};
        int a = 0;
        for(int& n : nums)a ^= n;
        a &= -a;
        for(int& n : nums){
            if(n & a)ans[0]^=n;
            else ans[1]^=n;
        }
        return ans;
    }
};
// Problem

// Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, 
// with the colors in the order red, white and blue.

// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.


// Example

// Input: [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int col[3]={0,0,0};
        for(int c : nums)col[c]++;
        int j=0;
        for(int i=0;i<nums.size();i++){
            while(col[j]==0)j++;
            nums[i]=j;
            col[j]--;
        }
    }
};
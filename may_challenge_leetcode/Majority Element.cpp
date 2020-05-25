// Problem

// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
// You may assume that the array is non-empty and the majority element always exist in the array.

// Example

// Input: [3,2,3]
// Output: 3

// Input: [2,2,1,1,1,2,2]
// Output: 2



//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int n = nums.size();
      unordered_map<int,int> cnts;
      for(int i : nums){
        cnts[i]++;
        if(cnts[i]>n/2)
          return i;
      }
      return 0;
    }
};
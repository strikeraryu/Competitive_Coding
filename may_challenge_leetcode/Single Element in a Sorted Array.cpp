// Problem

// You are given a sorted array consisting of only integers where every element appears exactly twice,
// except for one element which appears exactly once. Find this single element that appears only once.
// Follow up: Your solution should run in O(log n) time and O(1) space.


// Example


// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2

// Input: nums = [3,3,7,7,10,11,11]
// Output: 10

// Constraints:

// 1 <= nums.length <= 10^5
// 0 <= nums[i] <= 10^5

//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
  int bs(vector<int> nums,int s,int e){
    int m = (s+e)/2;
    int n=nums.size();
    if(s>=e)return nums[m];
    if((m!=0 && nums[m]==nums[m-1] && (m-1)%2) || (m!=n-1 && nums[m]==nums[m+1] && m%2))
      return bs(nums,s,m-1);
    else if((m!=0 && nums[m]==nums[m-1] && (m-1)%2==0) || (m!=n && nums[m]==nums[m+1] && m%2==0))
      return bs(nums,m+1,e);
    else return nums[m];
  }
public:
    int singleNonDuplicate(vector<int>& nums) {
        return bs(nums,0,nums.size()-1);
    }
};
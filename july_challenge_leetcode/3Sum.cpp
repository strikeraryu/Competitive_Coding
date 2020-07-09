// Problem

// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
// Find all unique triplets in the array which gives the sum of zero.

// Note:

// The solution set must not contain duplicate triplets.



// Example

// Given array nums = [-1, 0, 1, 2, -1, -4],

// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]



//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int j = i+1;
            int k = n-1;
            while(j<k){
               if(k<n-1 && nums[k]==nums[k+1]){k--;continue;}
                
                if(nums[i] + nums[j] + nums[k]>0)k--;
                else if(nums[i] + nums[j] + nums[k]<0)j++;
                else if(nums[i] + nums[j] + nums[k]==0){
                    ret.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
            }
        }
        return ret;
    }
};
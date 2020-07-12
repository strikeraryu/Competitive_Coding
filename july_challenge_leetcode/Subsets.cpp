// Problem

// Given a set of distinct integers, nums, return all possible subsets (the power set).

// Note: The solution set must not contain duplicate subsets.



// Example

// Input: nums = [1,2,3]
// Output:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;


class Solution {
    void all_sets(vector<int> nums,vector<int> curr, int i, vector<vector<int>> &pwr_set){
        if(i>=nums.size())pwr_set.push_back(curr);
        else{
            vector<int> tmp = curr;
            all_sets(nums,tmp,i+1,pwr_set);
            tmp.push_back(nums[i]);
            all_sets(nums,tmp,i+1,pwr_set);
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> tmp;
        all_sets(nums,tmp,0,ret);
        return ret;
    }
};
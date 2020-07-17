// Problem

// Given a non-empty array of integers, return the k most frequent elements.



// Example

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

// Input: nums = [1], k = 1
// Output: [1]


// Constraints:

// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
// It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
// You can return the answer in any order.


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<pair<int,int>> v;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            cnt++;
            if(i==nums.size()-1 || nums[i]!=nums[i+1]){
                v.push_back({cnt,nums[i]});
                cnt=0;
            }
        }
        vector<int> ret;
        sort(v.begin(),v.end(), greater<pair<int,int>>());
        for(int i=0;i<k;i++)ret.push_back(v[i].second);
        return ret;
    }
};
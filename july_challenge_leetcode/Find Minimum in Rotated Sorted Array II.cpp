// Problem

// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
// Find the minimum element.
// The array may contain duplicates.

// Example

// Input: [2,2,2,0,1]
// Output: 0

// Input: [1,3,5]
// Output: 1


//-----------------------------------------------------------------------------------------------------
// Solution
#include <bits/stdc++.h>
using namespace std;


class Solution {
    int ind_min(vector<int> &v,int l,int h){
        if(l>=h)return l;
        int m = (l+h)/2;
        if(v[m]>v[h])return ind_min(v,m+1,h);
        else if(v[m]<v[h])return ind_min(v,l,m);
        return ind_min(v,l,h-1);
    }
public:
    int findMin(vector<int>& nums) {
        int n =nums.size();
        return nums[ind_min(nums,0,n-1)];
    }
};
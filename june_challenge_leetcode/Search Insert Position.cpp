// Problem

// Given a sorted array and a target value, return the index if the target is found. 
// If not, return the index where it would be if it were inserted in order.
// You may assume no duplicates in the array.


// Example

// Input: [1,3,5,6], 5
// Output: 2

// Input: [1,3,5,6], 2
// Output: 1

// Input: [1,3,5,6], 7
// Output: 4

// Input: [1,3,5,6], 0
// Output: 0


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int find(vector<int> v,int x,int s,int e){
        if(s>=e)return s;
        int mid = (s+e)/2;
        if(v[mid]==x)return mid;
        else if(v[mid]>x)return find(v,x,s,mid-1);
        else return find(v,x,mid+1,e);
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        int ind =  find(nums,target,0,nums.size()-1);
        if(nums[ind]>=target)return ind;
        return ind+1;
    }
};
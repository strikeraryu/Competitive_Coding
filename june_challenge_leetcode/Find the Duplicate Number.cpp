// Problem

// Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
// prove that at least one duplicate number must exist. Assume that there is only one duplicate number, the duplicate one.



// Example

// Input: [1,3,4,2,2]
// Output: 2

// Input: [3,1,3,4,2]
// Output: 3


// Constraints:

// You must not modify the array (assume the array is read only).
// You must use only constant, O(1) extra space.
// Your runtime complexity should be less than O(n2).
// There is only one duplicate number in the array, but it could be repeated more than once.


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[0];
        int slow = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(fast!=slow);
            
        fast = nums[0];
        while(fast!=slow){
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};
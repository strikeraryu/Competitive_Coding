// Problem

// Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

// The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

// You may assume the integer does not contain any leading zero, except the number 0 itself.



// Example

// Input: [1,2,3]
// Output: [1,2,4]

// Input: [4,3,2,1]
// Output: [4,3,2,2]



//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size()-1;i>=0;i--){
            if(digits[i]==9 && i==0){
                digits[i] = 1;
                digits.push_back(0);
            }
            else if(digits[i]==9) digits[i] = 0;
            else{
                digits[i]++;
                return digits;
            }
        }
        return digits;
    }
};
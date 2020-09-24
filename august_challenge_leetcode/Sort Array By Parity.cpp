// Problem

// Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

// You may return any answer array that satisfies this condition




// Example

// Input: [3,1,2,4]
// Output: [2,4,3,1]


// Note:

// 1 <= A.length <= 5000
// 0 <= A[i] <= 5000




//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int l = 0,r = A.size()-1;
        vector<int> ans(r+1);
        for(int i=0;i<A.size();i++){
            if(A[i]%2){
                ans[r]=A[i];
                r--;
            }
            else{
                ans[l]=A[i];
                l++;
            }
        }
        return ans;
    }
};
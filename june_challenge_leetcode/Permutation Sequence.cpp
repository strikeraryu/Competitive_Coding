// Problem

// The set [1,2,3,...,n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

// Example

// Input: n = 3, k = 3
// Output: "213"

// Input: n = 4, k = 9
// Output: "2314"


// Constraints:

// Given n will be between 1 and 9 inclusive.
// Given k will be between 1 and n! inclusive.

//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        vector<double> fact(n);
        int tmp = 1;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
            fact[n-i] = tmp = tmp*i;
        }
        string ans = "";
        for(int i=1;i<n;i++){
            int ind = ceil(k/fact[i])-1;
            k -= fact[i]*ind;
            ans+=to_string(nums[ind]);
            nums.erase(nums.begin()+ind);
        }
        ans+=to_string(nums[0]);
        return ans;
    }
};


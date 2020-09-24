// Problem

// Given an array of integers arr, we need to sort the array performing a series of pancake flips.

// In one pancake flip we do the following steps:

// Choose an integer k where 1 <= k <= arr.length.
// Reverse the sub-array arr[1...k].
// For example, if arr = [3,2,1,4] and we performed a pancake flip choosing k = 3, we reverse the sub-array [3,2,1], 
// so arr = [1,2,3,4] after the pancake flip at k = 3.

// Return an array of the k-values of the pancake flips that should be performed in order to sort arr.
//  Any valid answer that sorts the array within 10 * arr.length flips will be judged as correct.




// Example

// Input: arr = [3,2,4,1]
// Output: [4,2,4,3]

// Input: arr = [1,2,3]
// Output: []



// Constraints:

// 1 <= arr.length <= 100
// 1 <= arr[i] <= arr.length
// All integers in arr are unique (i.e. arr is a permutation of the integers from 1 to arr.length).




//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void reverse(vector<int> &v, int n){
        for(int i=0;i<n/2.0;i++){
            int tmp = v[i];
            v[i] = v[n-i];
            v[n-i] = tmp;
        }
    }
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int lst = arr.size()-1;
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            int mx = INT_MIN, ind = 0;
            for(int j=0;j<=lst;j++){
                if(arr[j]>mx){
                    mx = arr[j];
                    ind = j;
                }
            }
            if(ind!=lst){
                if(ind!=0){ans.push_back(ind+1);reverse(arr,ind);}
                ans.push_back(lst+1);reverse(arr,lst);
            }
            lst--;
        }
        return ans;
    }
};
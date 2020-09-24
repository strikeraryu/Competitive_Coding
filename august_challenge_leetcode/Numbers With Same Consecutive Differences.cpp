// Problem

// Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.

// Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.

// You may return the answer in any order.




// Example

// Input: N = 3, K = 7
// Output: [181,292,707,818,929]

// Input: N = 2, K = 1
// Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]



// Note:

// 1 <= N <= 9
// 0 <= K <= 9


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void func(int a,int n,vector<int> &ans,int k){
        if((n==1 && a==0) || int(log10(a)+1)==n){
            ans.push_back(a);
        }
        else{
            if(a%10-k>=0){
                int x = a*10 + (a%10-k);
                func(x,n,ans,k);
            }
            if(a%10+k<=9 && (a%10-k)!=(a%10+k)){
                int x = a*10 + (a%10+k);
                func(x,n,ans,k);
            }
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=0;i<=9;i++){
            if(i==0 && n!=1)continue;
            func(i,n,ans,k);
        }
        return ans;
    }
};
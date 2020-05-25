// Problem

// Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

// Note:
// The length of num is less than 10002 and will be ≥ k.
// The given num does not contain any leading zero.



// Example

// Input: num = "1432219", k = 3
// Output: "1219"

// Input: num = "10200", k = 1
// Output: "200"



//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        for(int i=0;i<num.size();i++){
            if(num[0]=='0'){
                num.erase(0,1);
                i-=1;
            }
            else if(k==0)break;   
            else if(i==num.size()-1 || num[i]>num[i+1]){
                num.erase(i,1);
                i=max(-1,i-2);
                k--;
            }
        }
        if(num=="")return "0";
        return num;
    }
};
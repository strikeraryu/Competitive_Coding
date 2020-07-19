// Problem

// Given two binary strings, return their sum (also a binary string).

// The input strings are both non-empty and contains only characters 1 or 0.


// Example

// Input: a = "11", b = "1"
// Output: "100"

// Input: a = "1010", b = "1011"
// Output: "10101"


// Constraints:

// Each string consists only of '0' or '1' characters.
// 1 <= a.length, b.length <= 10^4
// Each string is either "0" or doesn't contain any leading zero.

//-----------------------------------------------------------------------------------------------------
// Solution
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int c = 0;
        for(int i=a.size()-1,j = b.size()-1;i>=0||j>=0||c!=0;i--,j--){
            int x = i<0||a[i]=='0'?0:1;
            int y = j<0||b[j]=='0'?0:1;
            int sum = x+y+c;
            if(sum==0 || sum==2)ans = "0" + ans;
            if(sum==1 || sum==3)ans = "1" + ans;
            c=sum>=2?1:0;
        }
        return ans;
    }
};
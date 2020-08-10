// Problem

// Given a column title as appear in an Excel sheet, return its corresponding column number.



// Example

// Input: "A"
// Output: 1

// Input: "AB"
// Output: 28

// Input: "ZY"
// Output: 701



// Constraints:

// 1 <= s.length <= 7
// s consists only of uppercase English letters.
// s is between "A" and "FXSHRXW".


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int p = 0, ans = 0;
        for(int j=s.size()-1;j>=0;j--,p++){
            ans += (int(s[j])-64)*pow(26,p);
        }
        return ans;
    }
};
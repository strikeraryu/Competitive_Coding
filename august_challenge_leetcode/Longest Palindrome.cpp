// Problem

// Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

// Letters are case sensitive, for example, "Aa" is not considered a palindrome here.





// Example

// Input: s = "abccccdd"
// Output: 7


// Input: s = "a"
// Output: 1



//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> cnts;
        int p = 0;
        bool flg = false;
        for(char c : s)
            cnts[c]+=1;
        for(auto itr=cnts.begin();itr!=cnts.end();itr++){
            if(itr->second%2==1)flg = true;
            p += (itr->second)/2;
        }
        return flg?p*2+1:p*2;
    }
};
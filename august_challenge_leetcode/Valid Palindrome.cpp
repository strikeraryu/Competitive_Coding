// Problem

// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

// Note: For the purpose of this problem, we define empty string as valid palindrome.g.



// Example

// Input: "A man, a plan, a canal: Panama"
// Output: true

// Input: "race a car"
// Output: false



// Constraints:

// s consists only of printable ASCII characters.


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            if(!isalnum(s[i])){i++;continue;}
            if(!isalnum(s[j])){j--;continue;}
            if(tolower(s[i])!=tolower(s[j]))return false;
            i++;j--;
        }
        return true;
    }
};
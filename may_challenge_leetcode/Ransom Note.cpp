// Problem

// Given an arbitrary ransom note string and another string containing letters from all the magazines, 
// write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.
// Each letter in the magazine string can only be used once in your ransom note.



// Example

// Input: ransomNote = "a", magazine = "b"
// Output: false

// Input: ransomNote = "aa", magazine = "ab"
// Output: false



// Constraints:

// You may assume that both strings contain only lowercase letters.

//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
      unordered_map<char,int> dp;
      for(char c : ransomNote)dp[c]++;
      for(char c : magazine){
        auto itr = dp.find(c);
        if(itr!=dp.end()){
          dp[c]--;
          if(dp[c]==0)dp.erase(itr);
        }
      }
      if(dp.empty())return true;
      return false;
    }
};
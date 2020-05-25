// Problem

// You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  
// Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.
// The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, 
// so "a" is considered a different type of stone from "A".



// Example

// Input: J = "aA", S = "aAAbbbb"
// Output: 3

// Input: J = "z", S = "ZZ"
// Output: 0


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
      unordered_map<char,bool> m;
      int cnt = 0;
      for(char c : J)m[c]=true;
      for(char c : S)if(m.count(c)==1)cnt++;
      return cnt;
    }
};
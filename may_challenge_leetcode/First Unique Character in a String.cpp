// Problem

// Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.


// Example

// s = "leetcode"
// return 0.

// s = "loveleetcode",
// return 2.



// Constraints:

// You may assume the string contain only lowercase letters.


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
      unordered_map<char,int> cnts;
      queue<int> q;
      for(int i=0;i<s.size();i++){
        cnts[s[i]]++;
        if(cnts[s[i]]==1)
          q.push(i);
      }
      while(!q.empty()){
        int ind = q.front();
        q.pop();
        if(cnts[s[ind]]==1)
          return ind;
      }
      return -1;
    }
};
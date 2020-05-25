// Problem

// Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words,
// one of the first string's permutations is the substring of the second string.



// Example

// Input: s1 = "ab" s2 = "eidbaooo"
// Output: True

// Input:s1= "ab" s2 = "eidboaoo"
// Output: False


// Constraints:

// The input strings only contain lower case letters.
// The length of both given strings is in range [1, 10,000].

//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string p, string s) {
        int n = s.size(), k = p.size();
        vector<int> p_cnt(26),tmp_cnt(26);
        vector<int> ans;
        for(int i=0;i<k;i++) p_cnt[int(p[i])-97]++;
        for(int i=0;i<n;i++){
            tmp_cnt[int(s[i])-97]++;
            if(i>=k) tmp_cnt[int(s[i-k])-97]--;
            if(tmp_cnt==p_cnt)return true;
        }
        return false;
    }
};  
// Problem

// Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
// Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
// The order of output does not matter.



// Example

// Input:
// s: "cbaebabacd" p: "abc"
// Output:
// [0, 6]

// Input:
// s: "abab" p: "ab"
// Output:
// [0, 1, 2]


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), k = p.size();
        vector<int> p_cnt(26),tmp_cnt(26);
        vector<int> ans;
        for(int i=0;i<k;i++) p_cnt[int(p[i])-97]++;
        for(int i=0;i<n;i++){
            tmp_cnt[int(s[i])-97]++;
            if(i>=k) tmp_cnt[int(s[i-k])-97]--;
            if(tmp_cnt==p_cnt)ans.push_back(i-k+1);
        }
        return ans;
    }
};
// Problem

// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

// Note:

// The same word in the dictionary may be reused multiple times in the segmentation.
// You may assume the dictionary does not contain duplicate words.


// Example

// Input:
// s = "catsanddog"
// wordDict = ["cat", "cats", "and", "sand", "dog"]
// Output:
// [
//   "cats and dog",
//   "cat sand dog"
// ]


// Input:
// s = "pineapplepenapple"
// wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
// Output:
// [
//   "pine apple pen apple",
//   "pineapple pen apple",
//   "pine applepen apple"
// ]


// Input:
// s = "catsandog"
// wordDict = ["cats", "dog", "sand", "and", "cat"]
// Output:
// []



//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void brk(string &s, unordered_set<string> &dict, vector<string> &ans, string curr, int ind){
        if(ind>=s.size())ans.push_back(curr.substr(0,curr.size()-1));
        else{
            string tmp = "";
            for(int i=ind;i<s.size();i++){
                tmp+=s[i];
                if(dict.count(tmp)!=0)
                    brk(s, dict, ans, curr+tmp+" ", i+1);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<string> ans;
        vector<int> dp(n);
        for(int i=0;i<n;i++){
            string tmp = "";
            for(int j=i;j<n;j++){
                tmp+=s[j];
                if((i==0 || dp[i-1]==1) && dict.count(tmp)!=0)
                    dp[j]=1;
            }
        }
        if(dp[n-1]==0)return {};
        brk(s, dict, ans, "", 0);
        return ans;
    }
};
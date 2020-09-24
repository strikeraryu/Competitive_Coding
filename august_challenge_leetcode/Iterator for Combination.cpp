// Problem

// Design an Iterator class, which has:

// A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
// A function next() that returns the next combination of length combinationLength in lexicographical order.
// A function hasNext() that returns True if and only if there exists a next combination.



// Example

// CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

// iterator.next(); // returns "ab"
// iterator.hasNext(); // returns true
// iterator.next(); // returns "ac"
// iterator.hasNext(); // returns true
// iterator.next(); // returns "bc"
// iterator.hasNext(); // returns false




// Constraints:

// 1 <= combinationLength <= characters.length <= 15
// There will be at most 10^4 function calls per test.
// It's guaranteed that all calls of the function next are valid.

//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class CombinationIterator {
    void findall(int i, int curr_l, int l, string s, string chars, vector<string> &all_cmb){
        if(curr_l==l){all_cmb.push_back(s);return;}
        if(i>=chars.size())return;
        findall(i+1,curr_l+1,l,s+chars[i],chars,all_cmb);
        findall(i+1,curr_l,l,s,chars,all_cmb);
    }
public:
    vector<string> all_cmb;
    int i=0;
    CombinationIterator(string characters, int combinationLength) {
        findall(0,0,combinationLength,"",characters,all_cmb);
        for(string s : all_cmb)cout<<s<<" ";
    }
    
    string next() {
        return all_cmb[i++];
    }
    
    bool hasNext() {
        return i<all_cmb.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
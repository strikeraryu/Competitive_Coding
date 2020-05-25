// Problem

// Implement a trie with insert, search, and startsWith methods.



// Example

// Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // returns true
// trie.search("app");     // returns false
// trie.startsWith("app"); // returns true
// trie.insert("app");   
// trie.search("app");     // returns true



// Constraints:

// You may assume that all inputs are consist of lowercase letters a-z.
// All inputs are guaranteed to be non-empty strings.

//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie *child[26];
    bool end;
    Trie() {
        for(int i=0;i<26;i++)child[i]=NULL;
        end = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *curr = this;
        for(char c : word){
            if(curr->child[int(c)-97]==NULL)
                curr->child[int(c)-97] = new Trie();
            curr = curr->child[int(c)-97];
        }
        curr->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *curr = this;
        for(char c : word){
            if(curr->child[int(c)-97]==NULL) {cout<<"x";return false;}
            curr = curr->child[int(c)-97]; 
        }
        return curr->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *curr = this;
        for(char c : prefix){
            if(curr->child[int(c)-97]==NULL) {cout<<"x";return false;}
            curr = curr->child[int(c)-97]; 
        }
        return true;
    }
};
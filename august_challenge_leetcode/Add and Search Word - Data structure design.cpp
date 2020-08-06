// Problem

// Design a data structure that supports the following two operations:

// void addWord(word)
// bool search(word)
// search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.



// Example

// addWord("bad")
// addWord("dad")
// addWord("mad")
// search("pad") -> false
// search("bad") -> true
// search(".ad") -> true
// search("b..") -> true



// Note:
// You may assume that all words are consist of lowercase letters a-z.

//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class WordDictionary {
    
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
            bool search(string word, int ind, Trie *node) {
                if(ind==word.size())return node->end;
                if(word[ind]=='.'){
                    for(int i=0;i<26;i++){
                        if(node->child[i] && search(word, ind+1, node->child[i]))
                            return true;
                    }
                }
                else{
                    if(node->child[int(word[ind])-97] && search(word, ind+1, node->child[int(word[ind])-97]))
                        return true;
                }
                return false;
            }
        };
    
    
    
    
public:
    /** Initialize your data structure here. */
    Trie t;
    WordDictionary() {
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        t.insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return t.search(word, 0, &t);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
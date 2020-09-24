// Problem

// Implement the StreamChecker class as follows:

// StreamChecker(words): Constructor, init the data structure with the given words.
// query(letter): returns true if and only if for some k >= 1, the last k characters queried (in order from oldest to newest, 
// including this letter just queried) spell one of the words in the given list.




// Example

// StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init the dictionary.
// streamChecker.query('a');          // return false
// streamChecker.query('b');          // return false
// streamChecker.query('c');          // return false
// streamChecker.query('d');          // return true, because 'cd' is in the wordlist
// streamChecker.query('e');          // return false
// streamChecker.query('f');          // return true, because 'f' is in the wordlist
// streamChecker.query('g');          // return false
// streamChecker.query('h');          // return false
// streamChecker.query('i');          // return false
// streamChecker.query('j');          // return false
// streamChecker.query('k');          // return false
// streamChecker.query('l');          // return true, because 'kl' is in the wordlist


// Constraints:

// 1 <= words.length <= 2000
// 1 <= words[i].length <= 2000
// Words will only consist of lowercase English letters.
// Queries will only consist of lowercase English letters.
// The number of queries is at most 40000.



//-----------------------------------------------------------------------------------------------------
// Solution


#include <bits/stdc++.h>
using namespace std;

class StreamChecker {
public:
    class Trie {
        public:
            /** Initialize your data structure here. */
            Trie *child[26];
            bool end;
            Trie() {
                for(int i=0;i<26;i++)child[i]=NULL;
                end = false;
            }

            void insert(string word) {
                Trie *curr = this;
                for(int i=word.size()-1;i>=0;i--){
                    char c = word[i];
                    if(curr->child[int(c)-97]==NULL)
                        curr->child[int(c)-97] = new Trie();
                    curr = curr->child[int(c)-97];
                }
                curr->end = true;
            }
        };
    Trie t;
    vector<int> strm;
    StreamChecker(vector<string>& words) {
        for(string w : words)t.insert(w);
    }
    
    bool query(char letter) {
        strm.push_back(letter);
        int i = strm.size()-1;
        Trie* root = &t;
        while(root!=NULL && i>=0){
            char c = strm[i];
            if(root->child[int(c)-97]!=NULL)root = root->child[int(c)-97];
            else return false;
            if(root->end)return true;
            i--;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
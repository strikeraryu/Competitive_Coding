// Problem

// Given a 2D board and a list of words from the dictionary, find all words in the board.

// Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. 
// The same letter cell may not be used more than once in a word.



// Example

// Input: 
// board = [
//   ['o','a','a','n'],
//   ['e','t','a','e'],
//   ['i','h','k','r'],
//   ['i','f','l','v']
// ]
// words = ["oath","pea","eat","rain"]

// Output: ["eat","oath"]


// Constraints:

// All inputs are consist of lowercase letters a-z.
// The values of words are distinct.

//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
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
                    if(curr->child[int(c)-97]==NULL) return false;
                    curr = curr->child[int(c)-97]; 
                }
                return curr->end;
            }

            /** Returns if there is any word in the trie that starts with the given prefix. */
            bool startsWith(string prefix) {
                Trie *curr = this;
                for(char c : prefix){
                    if(curr->child[int(c)-97]==NULL) return false;
                    curr = curr->child[int(c)-97]; 
                }
                return true;
            }
        };
public:
    map<string,int> log;
    vector<string> ans;
    void dfs(vector<vector<char>>& board, string s, int i, int j, vector<vector<int>> vis,Trie trie){
        s += board[i][j];
        if(!trie.startsWith(s))return;
        if(trie.search(s) && log[s]==0){
            ans.push_back(s);
            log[s] = 1;
        }
        int D[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vis[i][j] = 1;
        for(auto d : D){
            int ni = i + d[0];
            int nj = j + d[1];
            if(ni>=0 && ni<board.size() && nj>=0 && nj<board[0].size() && vis[ni][nj]==0)
                dfs(board, s, ni, nj, vis, trie);
        }
        vis[i][j] = 0;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words){
        Trie trie;  
        for(string word : words)trie.insert(word);
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dfs(board, "", i, j, vis, trie);
            }
        }
        return ans;
    }
};
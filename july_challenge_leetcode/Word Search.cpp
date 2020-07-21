// Problem

// Given a 2D board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cell, 
// where "adjacent" cells are those horizontally or vertically neighboring. 
// The same letter cell may not be used more than once.


// Example

// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]

// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.


// Constraints:

// board and word consists only of lowercase and uppercase English letters.
// 1 <= board.length <= 200
// 1 <= board[i].length <= 200
// 1 <= word.length <= 10^3

//-----------------------------------------------------------------------------------------------------
// Solution
#include <bits/stdc++.h>
using namespace std;


class Solution {
    bool find(vector<vector<char>> &v, string s, int ind, int i, int j, int n, int m){
        if(i<0 || i>=n || j<0 || j>=m || v[i][j] != s[ind])return false;
        if(ind == s.size()-1)return true;
        int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        char c = v[i][j];
        v[i][j] = '#';
        for(auto d : dir)
            if(find(v, s, ind+1, i + d[0], j + d[1], n, m))return true;
        v[i][j] = c;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(find(board, word, 0, i, j, n, m))return true;
        return false;
    }
};
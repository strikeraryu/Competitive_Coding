// Problem

// An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).
// Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, 
// and a pixel value newColor, "flood fill" the image.

// To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel,
// plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), 
// and so on. Replace the color of all of the aforementioned pixels with the newColor.

// At the end, return the modified image.



// Example

// Input: 
// image = [[1,1,1],[1,1,0],[1,0,1]]
// sr = 1, sc = 1, newColor = 2
// Output: [[2,2,2],[2,2,0],[2,0,1]]



// Constraints:

// The length of image and image[0] will be in the range [1, 50].
// The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
// The value of each color in image[i][j] and newColor will be an integer in [0, 65535].

//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
      int n = image.size();
      int m = image[0].size();
      int col = image[sr][sc];
      vector<vector<int>> vis(n, vector<int>(m));
      queue<pair<int,int>> q;
      int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
      auto chk = [&](int x,int y){return x>=0 && x<n && y>=0 && y<m;};
      q.push({sr,sc});
      image[sr][sc] = newColor;
      while(!q.empty()){
        auto curr = q.front();
        q.pop();
        for(auto d : dir){
          int tmp_r = curr.first + d[0];
          int tmp_c = curr.second + d[1];
          if(chk(tmp_r,tmp_c) && !vis[tmp_r][tmp_c] && image[tmp_r][tmp_c]==col){
            vis[tmp_r][tmp_c] = 1;
            q.push({tmp_r,tmp_c});
            image[tmp_r][tmp_c] = newColor;
          }
        }
      }
      return image;
    }
};
// Problem

// In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
// Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
// We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.
// Return true if and only if the nodes corresponding to the values x and y are cousins.

// Example

// Input: root = [1,2,3,4], x = 4, y = 3
// Output: false

// Input: root = [1,2,3,null,4], x = 2, y = 3
// Output: false

// Constraints:

// The number of nodes in the tree will be between 2 and 100.
// Each node has a unique integer value from 1 to 100.


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
      pair<int,int> x_pos,y_pos;
      queue< pair<TreeNode*,int> > q;
      q.push({root,0});
      while(!q.empty()){
        TreeNode* curr = q.front().first;
        int curr_d = q.front().second;
        q.pop();
        if(curr->left){
          q.push({curr->left,curr_d+1});
          if(curr->left->val == x)
            x_pos = {curr_d+1,curr->val};
          else if(curr->left->val == y)
            y_pos = {curr_d+1,curr->val};
        }
        if(curr->right){
          q.push({curr->right,curr_d+1});
          if(curr->right->val == x)
            x_pos = {curr_d+1,curr->val};
          else if(curr->right->val == y)
            y_pos = {curr_d+1,curr->val};
        }
      }
      if(y_pos.first==x_pos.first && y_pos.second!=x_pos.second)
        return true;
      return false;
    }
};
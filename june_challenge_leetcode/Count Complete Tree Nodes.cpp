// Problem

// Given a complete binary tree, count the number of nodes.

// Note:
// Definition of a complete binary tree from Wikipedia:
// In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible.
// It can have between 1 and 2h nodes inclusive at the last level h.




// Example

// Input: 
//     1
//    / \
//   2   3
//  / \  /
// 4  5 6

// Output: 6


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
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
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 1;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
                cnt++;
            }
            if(curr->right){
                q.push(curr->right);
                cnt++;
            }
        }
        return cnt;
    }
};
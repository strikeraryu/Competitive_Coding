// Problem

// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
// An example is the root-to-leaf path 1->2->3 which represents the number 123.
// Find the total sum of all root-to-leaf numbers.

// Note: A leaf is a node with no children.




// Example


// Input: [1,2,3]
//     1
//    / \
//   2   3
// Output: 25

// Input: [4,9,0,5,1]
//     4
//    / \
//   9   0
//  / \
// 5   1
// Output: 1026



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
    void dfs(TreeNode* root, int &ans,int val_till_now){
        bool right = false,left = false;
        if(root->right!=NULL){
            dfs(root->right,ans,val_till_now*10+root->right->val);
            right = true;
        }
        
        if(root->left!=NULL){
            dfs(root->left,ans,val_till_now*10+root->left->val);
            left = true;
        }
        if(!right && !left)ans+=val_till_now;
    }
public:
    int sumNumbers(TreeNode* root) {
        if(root==NULL)return 0;
        int ans = 0;
        dfs(root,ans,root->val);
        return ans;
    }
};
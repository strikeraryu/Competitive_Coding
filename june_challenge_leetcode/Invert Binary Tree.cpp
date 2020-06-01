// Problem

// Invert a binary tree.



// Example

// Input
//      4
//    /   \
//   2     7
//  / \   / \
// 1   3 6   9

// Output
//      4
//    /   \
//   7     2
//  / \   / \
// 9   6 3   1



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
    void invert(TreeNode* root){
        if(root!=NULL){
            invert(root->left);
            invert(root->right);
            auto tmp = root->left;
            root->left = root->right;
            root->right = tmp;
        }
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};
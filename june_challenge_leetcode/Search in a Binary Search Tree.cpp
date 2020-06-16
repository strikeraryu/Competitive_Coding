// Problem

// Given the root node of a binary search tree (BST) and a value. 
// You need to find the node in the BST that the node's value equals the given value. 
// Return the subtree rooted with that node. If such node doesn't exist, you should return NULL.




// Example

// Input: 
// [4,2,7,1,3]
// 2
// Output: [2,1,3]


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
    TreeNode* searchBST(TreeNode* root, int val) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            if(curr->val==val)return curr;
            if(curr->left!=NULL)q.push(curr->left);
            if(curr->right!=NULL)q.push(curr->right);
        }
        return NULL;
    }
};
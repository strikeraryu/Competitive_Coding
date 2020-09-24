// Problem

// Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

// Basically, the deletion can be divided into two stages:

// Search for a node to remove.
// If the node is found, delete the node.
// Follow up: Can you solve it with time complexity O(height of tree)?



// Example

// Input: root = [5,3,6,2,4,null,7], key = 3
// Output: [5,4,6,2,null,null,7]

// Input: root = [5,3,6,2,4,null,7], key = 0
// Output: [5,3,6,2,4,null,7]

// Input: root = [], key = 0
// Output: []




// Constraints:

// The number of nodes in the tree is in the range [0, 104].
// -105 <= Node.val <= 105
// Each node has a unique value.
// root is a valid binary search tree.
// -105 <= key <= 105

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
    
    TreeNode* findmin(TreeNode* root){
        if(root==NULL)return NULL;
        while(root->left!=NULL)root=root->left;
        return root;
    }
    
    void del(TreeNode* &root, int val){
        if(root==NULL)return;
        if(val > root->val) del(root->right, val);
        else if(val < root->val) del(root->left, val);
        else if(root->left!=NULL && root->right!=NULL){
            int min_val = findmin(root->right)->val;
            root->val = min_val;
            del(root->right, min_val);
        }
        else{
            root = root->left==NULL?root->right:root->left;
        }
    }
    
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        del(root, key);
        return root;
    }
};
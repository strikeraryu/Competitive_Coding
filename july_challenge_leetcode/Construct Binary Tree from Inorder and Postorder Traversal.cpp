// Problem

// Given inorder and postorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

// Example

// Input: 3
// inorder = [9,3,15,20,7]
// postorder = [9,15,7,20,3]

// Output: 2
//     3
//    / \
//   9  20
//     /  \
//    15   7



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
    TreeNode* makeTree(vector<int> &in, vector<int> &post, int &p_ind, int s, int e){
        if(s>e)return NULL;
        
        int i_ind;
        for(i_ind=s;i_ind<=e;i_ind++)if(in[i_ind] == post[p_ind])break;
        
        TreeNode* root = new  TreeNode(post[p_ind--]);
        
        root->right = makeTree(in,post,p_ind,i_ind+1,e); 
        root->left = makeTree(in,post,p_ind,s,i_ind-1); 
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size()-1;
        return makeTree(inorder,postorder,n,0,n);
    }
};
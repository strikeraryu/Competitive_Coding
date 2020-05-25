// Problem

// Return the root node of a binary search tree that matches the given preorder traversal.
// (Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, 
// and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, 
// then traverses node.left, then traverses node.right.)
// It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.



// Example

// Input: [8,5,1,7,10,12]
// Output: [8,5,10,1,7,null,12]


// Constraints:

// 1 <= preorder.length <= 100
// 1 <= preorder[i] <= 10^8
// The values of preorder are distinct.

//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  TreeNode* add_rec(const vector<int>& preorder,int& ind,int limit)
  {
    if(ind==preorder.size() || preorder[ind]>limit)return NULL;
    int root_val = preorder[ind];
    TreeNode* root = new TreeNode(root_val);
    ind++;
    root->left = add_rec(preorder,ind,root_val);
    root->right = add_rec(preorder,ind,limit);
    return root;
  }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
      int ind = 0;
      return add_rec(preorder,ind,INT_MAX);
    }
};
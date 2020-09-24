// Problem

// Find the sum of all left leaves in a given binary tree.




// Example

//     3
//    / \
//   9  20
//     /  \
//    15   7

// There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.




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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)return 0;
        int sum = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            TreeNode* curr = q.front().first;
            int side = q.front().second;
            q.pop();
            if(curr->left==NULL && curr->right==NULL)
                sum+=side*curr->val;
            else{
                if(curr->left)q.push({curr->left,1});
                if(curr->right)q.push({curr->right,0});
            }
        }
        return sum;
    }
};
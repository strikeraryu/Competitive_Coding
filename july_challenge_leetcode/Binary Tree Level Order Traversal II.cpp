// Problem

// Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
// (ie, from left to right, level by level from leaf to root).




// Example

// Input: [3,9,20,null,null,15,7]
//     3
//    / \
//   9  20
//     /  \
//    15   7
// Output: [[15,7],[9,20],[3]]



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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL)return {};
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        q.push(root);
        ret.push_back({root->val});
        while(!q.empty()){
            int n = q.size();
            vector<int> lvl;
            while(n--){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left!=NULL){
                    q.push(curr->left);
                    lvl.push_back(curr->left->val);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                    lvl.push_back(curr->right->val);
                }
            }
            if(!lvl.empty())ret.push_back(lvl);
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
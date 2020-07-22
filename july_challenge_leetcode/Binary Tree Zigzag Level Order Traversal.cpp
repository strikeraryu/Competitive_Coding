// Problem

// Given a binary tree, return the zigzag level order traversal of its nodes' values. 
// (ie, from left to right, then right to left for the next level and alternate between).


// Example

//     3
//    / \
//   9  20
//     /  \
//    15   7

// [
//   [3],
//   [20,9],
//   [15,7]
// ]


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)return {};
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        q.push(root);
        ret.push_back({root->val});
        int lvl_no = 1;
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
            if(lvl_no%2)reverse(lvl.begin(),lvl.end());
            if(!lvl.empty())ret.push_back(lvl);
            lvl_no++;
        }
        return ret;  
    }
};
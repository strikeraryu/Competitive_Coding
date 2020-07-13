// Problem

// Given two binary trees, write a function to check if they are the same or not.

// Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
 


// Example

// Input:     1         1
//           / \       / \
//          2   3     2   3

//         [1,2,3],   [1,2,3]

// Output: true


// Input:     1         1
//           /           \
//          2             2

//         [1,2],     [1,null,2]

// Output: false


// Input:     1         1
//           / \       / \
//          2   1     1   2

//         [1,2,1],   [1,1,2]

// Output: false


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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)return true;
        if(p==NULL || q==NULL)return false;
        queue<TreeNode*> q1,q2;
        if(p->val!=q->val)return false;
        q1.push(q);
        q2.push(p);
        while(!q1.empty() && !q1.empty()){
            auto curr1=q1.front();
            auto curr2=q2.front();
            q1.pop();
            q2.pop();
            if(curr1->right!=NULL && curr2->right!=NULL){
                if(curr1->right->val!=curr2->right->val)return false;
                q1.push(curr1->right);
                q2.push(curr2->right);
            }
            else if(curr1->right!=NULL || curr2->right!=NULL)return false;
            
            if(curr1->left!=NULL && curr2->left!=NULL){
                if(curr1->left->val!=curr2->left->val)return false;
                q1.push(curr1->left);
                q2.push(curr2->left);
            }
            else if(curr1->left!=NULL || curr2->left!=NULL)return false;
        }
        return true;
    }
};
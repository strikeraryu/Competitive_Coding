// Problem

// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it. 


// Example

// Input: root = [5,3,6,2,4,null,null,1], k = 3
//        5
//       / \
//      3   6
//     / \
//    2   4
//   /
//  1
// Output: 3



// Constraints:

// The number of elements of the BST is between 1 to 10^4.
// You may assume k is always valid, 1 ≤ k ≤ BST's total elements.


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
    int kthSmallest(TreeNode* root, int k) {
        map<int,int> vis;
        deque<TreeNode*> q;
        q.push_back(root);
        vis[root->val] = 0;
        int cnt = 0;
        while(!q.empty()){
            TreeNode* curr = q.back();
            q.pop_back();
            if(vis[curr->val]==1)
            cnt++;
            if(cnt==k)return curr->val;
            if(vis[curr->val]==0){
                while(curr!=NULL){ 
                    vis[curr->val]=1;
                    q.push_back(curr);
                    curr = curr->left;
                }
            }
            else if(vis[curr->val]==1 && curr->right!=NULL){
                curr=curr->right;
                q.push_back(curr);
                vis[curr->val]=0;
            }
        }
        return 0;
    }
};
// Problem

// Given a binary tree, write a function to get the maximum width of the given tree. 
// The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, 
// but some nodes are null.

// The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, 
// where the null nodes between the end-nodes are also counted into the length calculation.

// Note: Answer will in the range of 32-bit signed integer



// Example

// Input: 

//            1
//          /   \
//         3     2
//        / \     \  
//       5   3     9 

// Output: 4

// Input: 

//           1
//          /  
//         3    
//        / \       
//       5   3     

// Output: 2

// Input: 

//           1
//          / \
//         3   2 
//        /        
//       5      

// Output: 2

// Input: 

//           1
//          / \
//         3   2
//        /     \  
//       5       9 
//      /         \
//     6           7
// Output: 8



//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;


//Definition for a binary tree node.
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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        queue<pair<TreeNode*,long long int>> q;
        long long int max_width = 1;
        q.push({root,0});
        while(!q.empty()){
            int n = q.size();
            long long int lb=INT_MAX,ub=INT_MIN;
            while(n--){
                auto curr = q.front().first;
                long long int d = q.front().second; 
                q.pop();
                lb=min(lb,d);
                ub=max(ub,d);
                if(curr->right!=NULL){
                    int new_d;
                    if(d==0)new_d = 1;
                    else if(d<0)new_d = 2*d+1;
                    else if(d>0)new_d = 2*d;
                    q.push({curr->right,new_d});
                }
                if(curr->left!=NULL){
                    int new_d;
                    if(d==0)new_d = -1;
                    else if(d<0)new_d = 2*d;
                    else if(d>0)new_d = 2*d-1;
                    q.push({curr->left,new_d});
                }
            }
            long long int tmp = ub-lb;
            if((ub<0 && lb<0) || (ub>0 && lb>0))tmp++;
            max_width = max(max_width,tmp);
        }
        return max_width;
    }
};
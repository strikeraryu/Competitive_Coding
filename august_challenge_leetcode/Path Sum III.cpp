// Problem

// You are given a binary tree in which each node contains an integer value.

// Find the number of paths that sum to a given value.

// The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

// The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.


// Example

// root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

//       10
//      /  \
//     5   -3
//    / \    \
//   3   2   11
//  / \   \
// 3  -2   1

// Return 3. The paths that sum to 8 are:

// 1.  5 -> 3
// 2.  5 -> 2 -> 1
// 3. -3 -> 11


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
    void dfs(TreeNode* root, int sum, map<int,int> dp, int curr_sum, int &ans){
        if(curr_sum==sum)ans++;
        if(dp.count(curr_sum-sum)!=0 && sum)ans+=dp[curr_sum-sum];
        if(sum==0 && dp[curr_sum]>1)ans+=dp[curr_sum]-1;
        if(root->right){
            map<int,int> tmp = dp;
            tmp[curr_sum+root->right->val]++;
            dfs(root->right, sum, tmp, curr_sum+root->right->val, ans);
        }        
        if(root->left){
            map<int,int> tmp = dp;
            tmp[curr_sum+root->left->val]++;
            dfs(root->left, sum, tmp, curr_sum+root->left->val, ans);
        }
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root)return 0;
        int ans = 0;
        map<int,int> dp;
        dp[root->val]++;
        dfs(root, sum, dp, root->val, ans);
        return ans;
    }
};
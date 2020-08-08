// Problem

// Given a binary tree, return the vertical order traversal of its nodes values.

// For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).

// Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).

// If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.

// Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.


// Example

// Input: [3,9,20,null,null,15,7]
// Output: [[9],[3,15],[20],[7]]

// Input: [1,2,3,4,5,6,7]
// Output: [[4],[2],[1,5,6],[3],[7]]



// Note:
// The tree will have between 1 and 1000 nodes.
// Each node's value will be between 0 and 1000.

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>> v;
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> ans;
        int min_x=0,max_x=0;
        q.push({root, 0});
        v[0].push_back(root->val);
        int n = q.size();
        while(!q.empty()){
            map<int,vector<int>> tmp;
            while(n--)
            {
                TreeNode* curr = q.front().first;
                int x = q.front().second;
                q.pop();
                if(curr->right!=NULL){
                    q.push({curr->right,x+1});
                    max_x = max(x+1,max_x);
                    tmp[x+1].push_back(curr->right->val);
                }
                if(curr->left!=NULL){
                    q.push({curr->left,x+-1});
                    min_x = min(x-1,min_x);
                    tmp[x-1].push_back(curr->left->val);
                }
            }
            n=q.size();
            for(int i=min_x;i<=max_x;i++){
                sort(tmp[i].begin(),tmp[i].end());
                v[i].insert(v[i].end(), tmp[i].begin(), tmp[i].end());
            }
                
        }
        for(int i=min_x;i<=max_x;i++)
            ans.push_back(v[i]);
        return ans;
    }
};
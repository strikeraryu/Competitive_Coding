// Problem

// Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.


// Example

// Input: matrix =
// [
//   [0,1,1,1],
//   [1,1,1,1],
//   [0,1,1,1]
// ]
// Output: 15



// Constraints:

// 1 <= arr.length <= 300
// 1 <= arr[0].length <= 300
// 0 <= arr[i][j] <= 1


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if(matrix.size()==0)return 0;
        int n = matrix.size(), m = matrix[0].size(), ans = 0;    
        vector<vector<int>> v(n+1, vector<int>(m+1));
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)v[i+1][j+1] = matrix[i][j];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(v[i][j]==1){
                    v[i][j] += min(min(v[i][j-1],v[i-1][j]),v[i-1][j-1]);
                    ans+=v[i][j];
                }
            }
        }
        return ans;
    }
};
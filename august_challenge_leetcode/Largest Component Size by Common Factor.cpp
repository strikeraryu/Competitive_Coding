// Problem

// Given a non-empty array of unique positive integers A, consider the following graph:

// There are A.length nodes, labelled A[0] to A[A.length - 1];
// There is an edge between A[i] and A[j] if and only if A[i] and A[j] share a common factor greater than 1.
// Return the size of the largest connected component in the graph.



// Example

// Input: [4,6,15,35]
// Output: 4

// Input: [20,50,9,63]
// Output: 2

// Input: [2,3,6,7,4,12,21,39]
// Output: 8




// Constraints:

// 1 <= A.length <= 20000
// 1 <= A[i] <= 100000

//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
   vector<int> parent;
   vector<int> rank;
   int getParent(int x){
      if (parent[x] == -1)
      return x;
      return parent[x] = getParent(parent[x]);
   }
   void unionn(int x, int y){
      int parX = getParent(x);
      int parY = getParent(y);
      if (parX == parY)
      return;
      if (rank[parX] >= rank[parY]) {
         rank[parX] += rank[parY];
         parent[parY] = parX;
      } else {
         rank[parY] += rank[parX];
         parent[parX] = parY;
      }
   }
    
    int gcd(long long int a, long long int b){
        if(a==0)
            return b;
        return gcd(b%a,a);
    }
    
    int largestComponentSize(vector<int>& A) {
        int n = A.size(), ans = 0;
        parent = vector<int>(n, -1);
        rank = vector<int>(n, 1);
        map<int,int> log;
        for(int i=0;i<n;i++){
           for(int j=2;j*j<=A[i];j++){
               if(A[i]%j==0){
                   if(log.count(j)!=0) unionn(log[j],i);
                   else log[j] = i;
                   if(log.count(A[i]/j)!=0) unionn(log[A[i]/j],i);
                   else log[A[i]/j] = i;
               }
           }
            if(log.count(A[i])!=0) unionn(log[A[i]],i);
            else log[A[i]] = i;
        }
        vector<int> cnt(n);
        for(int i=0;i<n;i++){
            int x = getParent(i);
            cnt[x]++;
            ans = max(ans,cnt[x]);
        }
        return ans;
    }
};
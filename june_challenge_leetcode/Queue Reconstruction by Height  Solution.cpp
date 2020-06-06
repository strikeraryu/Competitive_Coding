// Problem

// Suppose you have a random list of people standing in a queue. 
// Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of 
// this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.




// Example

// Input:
// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

// Output:
// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]


// Constraints:

// The number of people is less than 1,100.

//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        vector<vector<int>> ret;
        sort(people.begin(),people.end(), [&](vector<int> a,vector<int> b){
            if(a[0]==b[0])return a[1]<b[1];
            return a[0]>b[0];
        });
        for(auto p : people){
            int x=0;
            while(true){
                if(x==p[1]){
                    ret.insert(ret.begin()+x,p);
                    break;
                }
                x++;
            }
        }
        return ret;
    }
};
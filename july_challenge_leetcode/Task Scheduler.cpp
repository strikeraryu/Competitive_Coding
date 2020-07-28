// Problem

// You are given a char array representing tasks CPU need to do. It contains capital letters A to Z where each letter represents a different task. Tasks could be done without the original order of the array. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

// However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

// You need to return the least number of units of times that the CPU will take to finish all the given tasks.



// Example

// Input: tasks = ["A","A","A","B","B","B"], n = 2
// Output: 8

// Input: tasks = ["A","A","A","B","B","B"], n = 0
// Output: 6

// Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
// Output: 16



// Constraints:

// The number of tasks is in the range [1, 10000].
// The integer n is in the range [0, 100].


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnts(26);
        int ans = 0;
        for(char& c : tasks) cnts[int(c)-65]++;
        sort(cnts.begin(),cnts.end());
        while(cnts[25]>0){
            for(int i=0;i<=n;i++){
                ans++;
                if(i>25)continue;
                if(cnts[25-i]>0)cnts[25-i]--;
                if(cnts[25-i]==0 && cnts[25]==0)break;
            }
            sort(cnts.begin(),cnts.end());
        }
        return ans;
    }
};
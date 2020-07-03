// Problem

// There are 8 prison cells in a row, and each cell is either occupied or vacant.

// Each day, whether the cell is occupied or vacant changes according to the following rules:

// If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
// Otherwise, it becomes vacant.
// (Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)

// We describe the current state of the prison in the following way: cells[i] == 1 if the i-th cell is occupied, else cells[i] == 0.

// Given the initial state of the prison, return the state of the prison after N days (and N such changes described above.)



// Example

// Input: cells = [0,1,0,1,1,0,0,1], N = 7
// Output: [0,0,1,1,0,0,0,0]

// Input: cells = [1,0,0,1,0,0,1,0], N = 1000000000
// Output: [0,0,1,1,1,1,1,0]


// Constraints:

// cells.length == 8
// cells[i] is in {0, 1}
// 1 <= N <= 10^9


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
       map<vector<int>,int> log;
        log[cells] = 0;
        for(int i=1;i<=N;i++){
            vector<int> tmp = cells;
            for(int j=0;j<8;j++){
                if(j!=0 && j!=7 && tmp[j-1]==tmp[j+1])
                    cells[j]=1;
                else cells[j]=0;
            }
            if(log.count(cells)!=0){
                N = (N-i)%(i-log[cells]);
                if(N>0) cells = prisonAfterNDays(cells, N);
                break;
            }
            log[cells]=i;
        }
        return cells;
    }
};
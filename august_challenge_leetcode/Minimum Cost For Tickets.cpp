// Problem

// In a country popular for train travel, you have planned some train travelling one year in advance.  The days of the year that you will travel is given as an array days.  Each day is an integer from 1 to 365.

// Train tickets are sold in 3 different ways:

// a 1-day pass is sold for costs[0] dollars;
// a 7-day pass is sold for costs[1] dollars;
// a 30-day pass is sold for costs[2] dollars.
// The passes allow that many days of consecutive travel.  For example, if we get a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.

// Return the minimum number of dollars you need to travel every day in the given list of days.



// Example

// Input: days = [1,4,6,7,8,20], costs = [2,7,15]
// Output: 11

// Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
// Output: 17

// Note:

// 1 <= days.length <= 365
// 1 <= days[i] <= 365
// days is in strictly increasing order.
// costs.length == 3
// 1 <= costs[i] <= 1000



//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        queue<pair<int,int>> lst7,lst30;
        int cost = 0;
        for(int d : days){
            while(!lst7.empty() && lst7.front().first+7<=d)lst7.pop();
            while(!lst30.empty() && lst30.front().first+30<=d)lst30.pop();
            lst7.push({d,cost+costs[1]});
            lst30.push({d,cost+costs[2]});
            cost = min(cost+costs[0],min(lst7.front().second,lst30.front().second));
        }
        return cost;
    }
};
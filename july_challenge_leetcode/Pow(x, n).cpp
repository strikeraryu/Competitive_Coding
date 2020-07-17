// Problem

// Implement pow(x, n), which calculates x raised to the power n (xn).



// Example

// Input: 2.00000, 10
// Output: 1024.00000

// Input: 2.10000, 3
// Output: 9.26100

// Input: 2.00000, -2
// Output: 0.25000

// Constraints:

// -100.0 < x < 100.0
// n is a 32-bit signed integer, within the range [−231, 231 − 1]


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)return 1;
        double ans = 1;
        bool flg = n>0;
        long long int a = abs(n);
        while(a>0){
            if(abs(a)%2==0){
                x *= x;
                a/=2;
            }
            ans *= x; 
            a--;
        }
        if(flg)return ans;
        else return 1/ans;
    }
};
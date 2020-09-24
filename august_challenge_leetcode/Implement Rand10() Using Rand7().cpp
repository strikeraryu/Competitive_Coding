// Problem

// Given the API rand7 which generates a uniform random integer in the range 1 to 7, write a function rand10 which generates a uniform random integer in the range 1 to 10. You can only call the API rand7 and you shouldn't call any other API. Please don't use the system's Math.random().

// Notice that Each test case has one argument n, the number of times that your implemented function rand10 will be called while testing. 

// Follow up:

// What is the expected value for the number of calls to rand7() function?
// Could you minimize the number of calls to rand7()?




// Example

// Input: n = 1
// Output: [2]

// Input: n = 2
// Output: [2,8]

// Input: n = 3
// Output: [3,8,10]



// Constraints:

// 1 <= n <= 105




//-----------------------------------------------------------------------------------------------------
// Solution


#include <bits/stdc++.h>
using namespace std;

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

// just a team function
int rand7(){
    return 1;
}

class Solution {
public:
    int rand10() {
        int sum = 0;
        for(int i=0;i<5;i++){
            sum+=rand7();
        }
        return sum%10 + 1;
    }
};
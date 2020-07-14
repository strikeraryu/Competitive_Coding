// Problem

// Given two numbers, hour and minutes. Return the smaller angle (in degrees) formed between the hour and the minute hand.



// Example

// Input: hour = 12, minutes = 30
// Output: 165

// Input: hour = 3, minutes = 30
// Output: 75

// Input: hour = 3, minutes = 15
// Output: 7.5

// Input: hour = 4, minutes = 50
// Output: 155

// Input: hour = 12, minutes = 0
// Output: 0



// Constraints:

// 1 <= hour <= 12
// 0 <= minutes <= 59
// Answers within 10^-5 of the actual value will be accepted as correct.


//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hr_ang = hour*30 + minutes*(.5);
        double min_ang = minutes*6;
        double ang = abs(hr_ang - min_ang);
        return min(360-ang, ang);
    }
};
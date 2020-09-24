# Problem

# Given an array of intervals where intervals[i] = [starti, endi]. For each interval i,
# check if there exists an interval j where startj >= endi, which can be called that interval j is on the right of interval i.

# For any interval i, you need to store the minimum interval j's index, 
# which means that the interval j has the minimum start point to build the "on the right of" relationship for interval i. 
# If the interval j doesn't exist, store -1 for the interval i. Finally, you should return the stored value of each interval as an array.




# Example

# Input: intervals = [[1,2]]
# Output: [-1]

# Input: intervals = [[3,4],[2,3],[1,2]]
# Output: [-1,0,1]

# Input: intervals = [[1,4],[2,3],[3,4]]
# Output: [-1,2,-1]


# Constraints:

# 1 <= intervals.length <= 2 * 104
# intervals[i].length == 2
# -106 <= starti <= endi <= 106
# The start points of each interval is unique.




# -----------------------------------------------------------------------------------------------------
# Solution

class Solution:
    def findRightInterval(self, intervals):
        n = len(intervals)
        for i in range(n):
            intervals[i].append(i)
            
        end_p = intervals[:]
        str_p = intervals[:]
        
        end_p.sort(key = lambda x : x[1])
        str_p.sort(key = lambda x : x[0])
        lst = [-1 for i in range(n)]
        i = 0; j = 0
        
        while i<n and j<n:
            while i<n and end_p[j][1] > str_p[i][0]: i+=1
            if i<n:
                lst[end_p[j][2]] = str_p[i][2]
            j+=1
            
        return lst
            
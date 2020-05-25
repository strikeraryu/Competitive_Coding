# Problem

# You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point.
# Check if these points make a straight line in the XY plane.

# Example

# Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
# Output: true

# Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
# Output: false

# Constraints:

# 2 <= coordinates.length <= 1000
# coordinates[i].length == 2
# -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
# coordinates contains no duplicate point.


#-----------------------------------------------------------------------------------------------------
# Solution

class Solution:
    def checkStraightLine(self, coords: List[List[int]]) -> bool:
        if len(coords)<=2:return True
        for i in range(2,len(coords)):
          d = []
          d.append(((coords[i][0]-coords[0][0])**2 + (coords[i][1]-coords[0][1])**2)**0.5)
          d.append(((coords[i][0]-coords[1][0])**2 + (coords[i][1]-coords[1][1])**2)**0.5)
          d.append(((coords[1][0]-coords[0][0])**2 + (coords[1][1]-coords[0][1])**2)**0.5)
          d.sort()
          print(d[0]+d[1],d[2])
          if round(d[0] + d[1],5) != round(d[2],5): return False
        return True
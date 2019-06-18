"""
223. Rectangle Area
Medium

247

489

Favorite

Share
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area

Example:

Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
Output: 45
Note:

Assume that the total area is never beyond the maximum possible value of int.
"""
"""
Runtime: 60 ms, faster than 75.34% of Python3 online submissions for Rectangle Area.
Memory Usage: 13.4 MB, less than 12.11% of Python3 online submissions for Rectangle Area.
"""

class Solution:
    def computeArea(self, A: int, B: int, C: int, D: int, E: int, F: int, G: int, H: int) -> int:
        area1=(C-A)*(D-B)
        area2=(G-E)*(H-F)
        left_bottom_inter=(max(A,E),max(B,F))
        right_top_inter=(min(C,G),min(D,H))
        area_inter=(max(0,right_top_inter[0]-left_bottom_inter[0]))*max(0,right_top_inter[1]-left_bottom_inter[1])
        return area1+area2-area_inter
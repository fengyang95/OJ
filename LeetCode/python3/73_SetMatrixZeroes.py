# -*- coding: utf-8 -*-
# @Time    : 2019/6/12 13:44
# @Author  : Yuanpeng Li
# @FileName: 73_SetMatrixZeroes.py
"""
73. Set Matrix Zeroes
Medium

1061

192

Favorite

Share
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input:
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output:
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
"""
"""
Runtime: 96 ms, faster than 82.97% of Python3 online submissions for Set Matrix Zeroes.
Memory Usage: 13.4 MB, less than 93.16% of Python3 online submissions for Set Matrix Zeroes.
"""
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        if len(matrix)<1:
            return
        nr,nc=len(matrix),len(matrix[0])
        zero_position=[]
        for i in range(nr):
            for j in range(nc):
                if matrix[i][j]==0:
                    zero_position.append((i,j))
        for (i,j) in zero_position:
            for col in range(nc):
                matrix[i][col]=0
            for row in range(nr):
                matrix[row][j]=0

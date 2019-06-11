# -*- coding: utf-8 -*-
# @Time    : 2019/6/11 19:17
# @Author  : Yuanpeng Li
# @FileName: 59_SpiralMatrixII.py
"""
59. Spiral Matrix II
Medium

442

80

Favorite

Share
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
Accepted
137,450
Submissions
293,969
"""
# 模拟
"""
Runtime: 36 ms, faster than 91.61% of Python3 online submissions for Spiral Matrix II.
Memory Usage: 13.2 MB, less than 28.36% of Python3 online submissions for Spiral Matrix II.
"""
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        matrix=[[1]*n for _ in range(n)]
        if n<2:
            return matrix
        left,right,top,down=0,n,0,n
        num=1
        index=0
        while True:
            if index==n*n:
                break
            for x in range(left,right):
                if index==n*n:
                    break
                matrix[top][x]=num
                num+=1
                index+=1
            top+=1
            for y in range(top,down):
                if index==n*n:
                    break
                index+=1
                matrix[y][right-1]=num
                num+=1
            right-=1

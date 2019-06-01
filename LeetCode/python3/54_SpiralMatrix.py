"""
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
"""


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if len(matrix) < 1:
            return matrix
        nr, nc = len(matrix), len(matrix[0])
        left, right, top, bottom = 0, nc, 0, nr
        res = []
        while (len(res) < (nr * nc)):
            # left->right
            for i in range(left, right):
                res.append(matrix[top][i])

            for j in range(top + 1, bottom):
                res.append(matrix[j][right - 1])

            for i in range(right - 2, left - 1, -1):
                res.append(matrix[bottom - 1][i])

            for j in range(bottom - 2, top, -1):
                res.append(matrix[j][left])

            left += 1
            right -= 1
            top += 1
            bottom -= 1
        return res[:nr * nc]

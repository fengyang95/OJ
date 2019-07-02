"""
329. Longest Increasing Path in a Matrix
Hard

1031

18

Favorite

Share
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

Input: nums =
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:

Input: nums =
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
"""

"""
Runtime: 380 ms, faster than 47.38% of Python3 online submissions for Longest Increasing Path in a Matrix.
Memory Usage: 14 MB, less than 55.11% of Python3 online submissions for Longest Increasing Path in a Matrix.
"""
# dfs
class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        nr, nc = len(matrix), len(matrix[0]) if len(matrix) != 0 else 0
        if nr == 0:
            return 0
        cache = [[0] * nc for _ in range(nr)]

        def get_neighbours(i, j):
            return [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]

        def dfs(i, j):
            if cache[i][j]:
                return cache[i][j]
            tmp = 0
            for r, c in get_neighbours(i, j):
                if r >= 0 and r < nr and c >= 0 and c < nc and matrix[r][c] > matrix[i][j]:
                    tmp = max(tmp, dfs(r, c))
            cache[i][j] = tmp + 1
            return cache[i][j]

        res = 0
        for i in range(nr):
            for j in range(nc):
                res = max(res, dfs(i, j))
        return res

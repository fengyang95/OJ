"""
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
"""


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if len(grid) == 0:
            return 0
        nr, nc = len(grid), len(grid[0])

        def dfs(grid, r, c):
            if r < 0 or c < 0 or r >= nr or c >= nc or grid[r][c] == '0':
                return
            if grid[r][c] == '1':
                grid[r][c] = '0'
                dfs(grid, r, c - 1)
                dfs(grid, r, c + 1)
                dfs(grid, r - 1, c)
                dfs(grid, r + 1, c)

        num = 0
        for r in range(nr):
            for c in range(nc):
                if grid[r][c] == '1':
                    num += 1
                    dfs(grid, r, c)
        return num

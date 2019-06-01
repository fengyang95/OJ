"""
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
"""
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        nr,nc=len(grid),len(grid[0])
        dp=[[0]*nc for _ in range(nr)]
        dp[0][0]=grid[0][0]
        for i in range(nr):
            for j in range(nc):
                if i==0 and j>0:
                    dp[i][j]=dp[i][j-1]+grid[i][j]
                if j==0 and i>0:
                    dp[i][j]=dp[i-1][j]+grid[i][j]
                if i>0 and j>0:
                    dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j]
        return dp[-1][-1]

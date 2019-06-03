"""
120. Triangle
Medium

1106

120

Favorite

Share
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
"""

"""
Runtime: 40 ms, faster than 95.68% of Python3 online submissions for Triangle.
Memory Usage: 14.4 MB, less than 13.26% of Python3 online submissions for Triangle.
"""
# 简单实现动态规划
# O(N^2)空间复杂度
class Solution:
    def minimumTotal(self, triangle) -> int:
        nr, nc = len(triangle), len(triangle)
        dp = [[triangle[0][0]] * nc for _ in range(nr)]
        #print(dp)
        for i in range(1, nr):
            dp[i][0] = dp[i - 1][0] + triangle[i][0]
            for j in range(1,i):
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j]
            dp[i][i]=dp[i-1][i-1]+triangle[i][i]
        res = dp[-1][0]
        for j in range(nc):
            res = min(res, dp[-1][j])
        #print(dp)
        return res


# O(N)复杂度解法
"""
Runtime: 40 ms, faster than 95.68% of Python3 online submissions for Triangle.
Memory Usage: 13.5 MB, less than 83.17% of Python3 online submissions for Triangle.
"""
# 关键是每行 列索引 从大到小！！！
class Solution2:
    def minimumTotal(self, triangle) -> int:
        dp=[0]*len(triangle)

        for i in range(len(triangle)):
            for j in range(len(triangle[i])-1,-1,-1):
                if j==0:
                    dp[j]=dp[j]+triangle[i][j]
                elif j==len(triangle[i])-1:
                    dp[j]=dp[j-1]+triangle[i][j]
                else:
                    dp[j]=min(dp[j-1],dp[j])+triangle[i][j]

        res=dp[0]
        for val in dp:
            res=min(res,val)
        #print(dp)
        return res

if __name__=='__main__':
    triangle=[[2],[3,4],[6,5,7],[4,1,8,3]]
    res=Solution2().minimumTotal(triangle)

    print(res)


# -*- coding: utf-8 -*-
# @Time    : 2019/7/18 14:35
# @Author  : Yuanpeng Li
# @FileName: 712_MinimumASCIIDeleteSumForTwoStrings.py
"""
712. Minimum ASCII Delete Sum for Two Strings
Medium

582

37

Favorite

Share
Given two strings s1, s2, find the lowest ASCII sum of deleted characters to make two strings equal.

Example 1:
Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
Example 2:
Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
Note:

0 < s1.length, s2.length <= 1000.
All elements of each string will have an ASCII value in [97, 122].
"""

"""
Runtime: 976 ms, faster than 23.25% of Python3 online submissions for Minimum ASCII Delete Sum for Two Strings.
Memory Usage: 17.6 MB, less than 57.47% of Python3 online submissions for Minimum ASCII Delete Sum for Two Strings.
"""
class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        nr,nc=len(s1),len(s2)
        dp=[[0]*(nc+1) for _ in range(nr+1)]
        for i in range(nr+1):
            for j in range(nc+1):
                if i==0 or j==0:
                    dp[i][j]=sum([ord(s1[index]) for index in range(i)])+sum([ord(s2[index]) for index in range(j)])
                elif s1[i-1]==s2[j-1]:
                    dp[i][j]=dp[i-1][j-1]
                else:
                    dp[i][j]=min(dp[i-1][j]+ord(s1[i-1]),dp[i][j-1]+ord(s2[j-1]))
        return dp[-1][-1]


"""
Runtime: 492 ms, faster than 93.21% of Python3 online submissions for Minimum ASCII Delete Sum for Two Strings.
Memory Usage: 14.2 MB, less than 87.36% of Python3 online submissions for Minimum ASCII Delete Sum for Two Strings.
"""
class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        if not s1:
            return sum([ord(s) for s in s2])
        if not s2:
            return sum([ord(s) for s in s1])
        nr, nc = len(s1), len(s2)
        dp = [[0] * nc for _ in range(nr)]
        if s1[0] == s2[0]:
            dp[0][0] = ord(s1[0])
        for i in range(1, nr):
            if s1[i] == s2[0]:
                dp[i][0] = ord(s2[0])
            else:
                dp[i][0] = dp[i - 1][0]

        for j in range(1, nc):
            if s1[0] == s2[j]:
                dp[0][j] = ord(s1[0])
            else:
                dp[0][j] = dp[0][j - 1]

        for i in range(1, nr):
            for j in range(1, nc):
                if s1[i] == s2[j]:
                    dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1] + ord(s1[i]))
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

        return sum([ord(s) for s in s1]) - dp[-1][-1] + sum([ord(s) for s in s2]) - dp[-1][-1]

# -*- coding: utf-8 -*-
# @Time    : 2019/7/17 11:26
# @Author  : Yuanpeng Li
# @FileName: 583_DeleteOperationForTwoStrings.py
"""
583. Delete Operation for Two Strings
Medium

726

19

Favorite

Share
Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.

Example 1:
Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Note:
The length of given words won't exceed 500.
Characters in given words can only be lower-case letters.
"""
"""
Runtime: 252 ms, faster than 92.31% of Python3 online submissions for Delete Operation for Two Strings.
Memory Usage: 14.9 MB, less than 83.21% of Python3 online submissions for Delete Operation for Two Strings.
"""


class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        if not word1:
            return len(word2)
        if not word2:
            return len(word1)
        nr, nc = len(word1), len(word2)
        dp = [[0] * nc for _ in range(nr)]
        if word1[0] == word2[0]:
            dp[0][0] = 1
        for i in range(1, nr):
            if word1[i] == word2[0]:
                dp[i][0] = 1
            else:
                dp[i][0] = dp[i - 1][0]

        for j in range(1, nc):
            if word1[0] == word2[j]:
                dp[0][j] = 1
            else:
                dp[0][j] = dp[0][j - 1]

        for i in range(1, nr):
            for j in range(1, nc):
                if word1[i] == word2[j]:
                    dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1] + 1)
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

        return len(word1) - dp[-1][-1] + len(word2) - dp[-1][-1]


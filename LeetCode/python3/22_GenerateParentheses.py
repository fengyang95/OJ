# -*- coding: utf-8 -*-
# @Time    : 2019/6/7 19:18
# @Author  : Yuanpeng Li
# @FileName: 22_GenerateParentheses.py
"""
22. Generate Parentheses
Medium

2776

172

Favorite

Share
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
Accepted
342,711
Submissions
622,255
"""

"""
Runtime: 40 ms, faster than 91.48% of Python3 online submissions for Generate Parentheses.
Memory Usage: 13.4 MB, less than 36.82% of Python3 online submissions for Generate Parentheses.
"""
# 直接递归
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        self.ans = []

        def helper(res, l, r):
            if l == 0 and r == 0:
                self.ans.append(res)
                return
            if l > 0:
                helper(res + '(', l - 1, r)
            if r > l:
                helper(res + ')', l, r - 1)

        helper('', n, n)
        return self.ans

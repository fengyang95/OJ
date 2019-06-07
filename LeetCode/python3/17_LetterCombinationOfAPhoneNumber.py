# -*- coding: utf-8 -*-
# @Time    : 2019/6/7 19:33
# @Author  : Yuanpeng Li
# @FileName: 17_LetterCombinationOfAPhoneNumber.py


"""
17. Letter Combinations of a Phone Number
Medium

2196

296

Favorite

Share
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
"""

# 回溯法
"""
Runtime: 36 ms, faster than 87.79% of Python3 online submissions for Letter Combinations of a Phone Number.
Memory Usage: 13.1 MB, less than 61.00% of Python3 online submissions for Letter Combinations of a Phone Number.
"""

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        num2str = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }

        self.ans = []

        def helper(res,num,n):
            if not num:
                return
            for letter in num2str[num[0]]:
                res+=letter
                if len(res)==n:
                    self.ans.append(res)
                else:
                    helper(res,num[1:],n)
                res=res[:-1]
        helper('',str(digits),len(digits))
        return self.ans

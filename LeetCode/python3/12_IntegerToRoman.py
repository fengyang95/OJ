# -*- coding: utf-8 -*-
# @Time    : 2019/6/6 14:22
# @Author  : Yuanpeng Li
# @FileName: 12_IntegerToRoman.py
"""
12. Integer to Roman
Medium

586

1857

Favorite

Share
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: 3
Output: "III"
Example 2:

Input: 4
Output: "IV"
Example 3:

Input: 9
Output: "IX"
Example 4:

Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 5:

Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
"""

"""
Runtime: 56 ms, faster than 87.93% of Python3 online submissions for Integer to Roman.
Memory Usage: 13.1 MB, less than 91.19% of Python3 online submissions for Integer to Roman.
"""

# 按规则模拟即可
class Solution:
    def intToRoman(self, num: int) -> str:
        thousand = num // 1000
        num %= 1000
        hundred = num // 100
        num %= 100
        ten = num // 10
        num %= 10
        s = ''
        if 0 < thousand < 4:
            s += ('M' * thousand)

        def helper(num, one, five, ten):
            res = ''
            if 0 < num < 4:
                res += (one * num)
            elif num == 4:
                res += (one + five)
            elif 5 <= num < 9:
                res += (five + (num - 5) * one)
            elif num == 9:
                res += (one + ten)
            return res

        if 0 < hundred < 10:
            s += helper(hundred, 'C', 'D', 'M')
        if 0 < ten < 10:
            s += helper(ten, 'X', 'L', 'C')
        if 0 < num < 10:
            s += helper(num, 'I', 'V', 'X')

        return s

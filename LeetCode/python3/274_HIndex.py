# -*- coding: utf-8 -*-
# @Time    : 2019/6/5 14:33
# @Author  : Yuanpeng Li
# @FileName: 274_HIndex.py
"""
274. H-Index
Medium

392

670

Favorite

Share
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

Example:

Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had
             received 3, 0, 6, 1, 5 citations respectively.
             Since the researcher has 3 papers with at least 3 citations each and the remaining
             two with no more than 3 citations each, her h-index is 3.
Note: If there are several possible values for h, the maximum one is taken as the h-index.
"""

# 排序再计数
"""
Runtime: 24 ms, faster than 71.65% of Python online submissions for H-Index.
Memory Usage: 11.9 MB, less than 72.62% of Python online submissions for H-Index.
"""
class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        length = len(citations)
        citations = sorted(citations)
        for i in range(length):
            h = length - i
            if (i == 0 or (citations[i - 1] <= h)) and citations[i] >= h:
                return h
        return 0


# -*- coding: utf-8 -*-
# @Time    : 2019/6/5 14:37
# @Author  : Yuanpeng Li
# @FileName: 275_HIndexII.py
"""
275. H-Index II
Medium

204

366

Favorite

Share
Given an array of citations sorted in ascending order (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

Example:

Input: citations = [0,1,3,5,6]
Output: 3
Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had
             received 0, 1, 3, 5, 6 citations respectively.
             Since the researcher has 3 papers with at least 3 citations each and the remaining
             two with no more than 3 citations each, her h-index is 3.
Note:

If there are several possible values for h, the maximum one is taken as the h-index.

Follow up:

This is a follow up problem to H-Index, where citations is now guaranteed to be sorted in ascending order.
Could you solve it in logarithmic time complexity?
"""

"""
Runtime: 140 ms, faster than 30.17% of Python online submissions for H-Index II.
Memory Usage: 16.9 MB, less than 5.22% of Python online submissions for H-Index II.
"""
# O(N)
class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        length = len(citations)
        for i in range(length):
            h = length - i
            if (i == 0 or (citations[i - 1] <= h)) and citations[i] >= h:
                return h
        return 0


##二分查找
"""
Runtime: 36 ms, faster than 96.07% of Python3 online submissions for H-Index II.
Memory Usage: 16.8 MB, less than 59.29% of Python3 online submissions for H-Index II.
"""
class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        length = len(citations)
        left,right=0,length-1
        while left<=right:
            mid=left+(right-left)//2
            if citations[mid]==length-mid:
                return length-mid
            elif citations[mid]>length-mid:
                right=mid-1
            else:
                left=mid+1
        return length-left

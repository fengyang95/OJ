# -*- coding: utf-8 -*-
# @Time    : 2019/6/8 14:15
# @Author  : Yuanpeng Li
# @FileName: 60_PermutationSequence.py

"""
60. Permutation Sequence
Medium

831

223

Favorite

Share
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
"""

#
"""
Runtime: 28 ms, faster than 99.68% of Python3 online submissions for Permutation Sequence.
Memory Usage: 12.9 MB, less than 99.71% of Python3 online submissions for Permutation Sequence.
"""
#
import math
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        l=list(range(1,n+1))
        res=''
        k-=1
        while n>0:
            fac=math.factorial(n-1)
            index=k//fac
            k=k%fac
            n-=1
            res+=str(l.pop(index))
        return res




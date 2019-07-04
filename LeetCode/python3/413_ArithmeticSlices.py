# -*- coding: utf-8 -*-
# @Time    : 2019/7/4 14:56
# @Author  : Yuanpeng Li
# @FileName: 413_ArithmeticSlices.py
"""
413. Arithmetic Slices
Medium

609

118

Favorite

Share
A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequence:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.


Example:

A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
"""

"""
Runtime: 28 ms, faster than 98.43% of Python3 online submissions for Arithmetic Slices.
Memory Usage: 13.2 MB, less than 76.90% of Python3 online submissions for Arithmetic Slices.
"""
class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        if len(A) < 3:
            return 0
        left, right = 0, 1
        diff = A[1] - A[0]
        res = []
        for right in range(2, len(A)):
            curr_diff = A[right] - A[right - 1]
            if curr_diff != diff:
                if right - left >= 3:
                    res.append(right - left)
                left = right - 1
                diff = A[right] - A[left]

        if right - left + 1 >= 3:
            res.append(right - left + 1)
        result = 0
        for n in res:
            result += (n - 1) * (n - 2) // 2
        return result



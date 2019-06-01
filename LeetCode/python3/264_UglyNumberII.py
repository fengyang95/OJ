"""
264. Ugly Number II
Medium

895

62

Favorite

Share
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:

1 is typically treated as an ugly number.
n does not exceed 1690.
"""

class Solution:
    def nthUglyNumber(self, n: int) -> int:
        res=[1]
        i2,i3,i5=0,0,0
        while len(res)<n:
            n2,n3,n5=res[i2]*2,res[i3]*3,res[i5]*5
            res.append(min(n2,n3,n5))
            if res[-1]==n2:
                i2+=1
            if res[-1]==n3:
                i3+=1
            if res[-1]==n5:
                i5+=1
        return res[-1]

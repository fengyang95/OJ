"""
279. Perfect Squares
Medium

1433

117

Favorite

Share
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
"""

import math
from collections import deque

class Solution:
    def numSquares(self, n: int) -> int:
        sqs=[i*i for i in range(1,1+int(math.sqrt(n)))]
        curr_level=[0]
        level=0
        while True:
            next_level=[]
            for a in curr_level:
                for b in sqs:
                    if a+b==n:
                        return level+1
                    if a+b<n:
                        next_level.append(a+b)
                    else:
                        continue
            curr_level=list(set(next_level))
            level+=1

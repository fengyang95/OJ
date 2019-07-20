"""
905. Sort Array By Parity
Easy

501

54

Favorite

Share
Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.



Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.


Note:

1 <= A.length <= 5000
0 <= A[i] <= 5000
"""

"""
Runtime: 92 ms, faster than 5.55% of Python3 online submissions for Sort Array By Parity.
Memory Usage: 14.4 MB, less than 5.56% of Python3 online submissions for Sort Array By Parity.
"""
# 双指针
class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        left=0
        right=len(A)-1
        while left<len(A) and right>=0 and left<right:
            if A[left]%2==1 and A[right]%2==0:
                A[left],A[right]=A[right],A[left]
                left+=1
                right-=1
            while left<len(A) and A[left]%2==0:
                left+=1
            while right>=0 and A[right]%2==1:
                right-=1
        return A

    
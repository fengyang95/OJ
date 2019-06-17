"""
136. Single Number
Easy

2489

93

Favorite

Share
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
"""
"""
Runtime: 36 ms, faster than 96.77% of Python3 online submissions for Single Number.
Memory Usage: 14.6 MB, less than 94.53% of Python3 online submissions for Single Number.
"""
# 利用异或运算，相同两个值异或为0，0与任何数异或为该数，依次异或剩下的为结果
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res=0
        for _,num in enumerate(nums):
            res=res^num
        return res
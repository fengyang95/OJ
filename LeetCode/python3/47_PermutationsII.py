# -*- coding: utf-8 -*-
# @Time    : 2019/6/7 23:14
# @Author  : Yuanpeng Li
# @FileName: 47_PermutationsII.py

"""
47. Permutations II
Medium

997

44

Favorite

Share
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
"""
"""
Runtime: 72 ms, faster than 85.41% of Python3 online submissions for Permutations II.
Memory Usage: 13.6 MB, less than 13.20% of Python3 online submissions for Permutations II.
"""
# 回溯 在46题的基础上加排序，去重
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        self.ans = []
        nums=sorted(nums)
        length=len(nums)
        def backtrack(nums, res):
            if len(res) ==length:
                self.ans.append(list(res))
                return
            for i in range(len(nums)):
                if i>0 and nums[i]==nums[i-1]:
                    continue
                backtrack(nums[:i]+nums[i+1:],res+[nums[i]])

        backtrack(nums, [])
        return self.ans

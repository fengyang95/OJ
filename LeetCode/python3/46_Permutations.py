# -*- coding: utf-8 -*-
# @Time    : 2019/6/7 22:50
# @Author  : Yuanpeng Li
# @FileName: 46_Permutations.py
"""
46. Permutations
Medium

2022

59

Favorite

Share
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
"""
"""
Runtime: 48 ms, faster than 94.96% of Python3 online submissions for Permutations.
Memory Usage: 13.7 MB, less than 5.14% of Python3 online submissions for Permutations.
"""
# 解法一
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        self.ans = []

        def helper(nums, index):
            nums = nums[:]
            if index == len(nums):
                self.ans.append(nums)
                return
            for i in range(index, len(nums)):
                nums[i], nums[index] = nums[index], nums[i]
                helper(nums, index + 1)

        helper(nums, 0)
        return self.ans


# 解法二
# @link{https://leetcode.com/problems/permutations/discuss/303484/Simple-python-iterative}
"""
Runtime: 48 ms, faster than 94.96% of Python3 online submissions for Permutations.
Memory Usage: 13.2 MB, less than 56.91% of Python3 online submissions for Permutations.
"""
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        for i in range(len(nums)):
            res = [pre + [follow] for pre in res for follow in nums if follow not in pre]
        return res


#解法三 回溯
"""
Runtime: 52 ms, faster than 81.69% of Python3 online submissions for Permutations.
Memory Usage: 13.2 MB, less than 52.50% of Python3 online submissions for Permutations.
"""
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:

        self.ans = []
        length=len(nums)
        def backtrack(nums, res):
            if len(res) ==length:
                self.ans.append(list(res))
                return
            for i,num in enumerate(nums):
                backtrack(nums[:i]+nums[i+1:],res+[num])

        backtrack(nums, [])
        return self.ans

# -*- coding: utf-8 -*-
# @Time    : 2019/6/13 23:33
# @Author  : Yuanpeng Li
# @FileName: 77_Combinations.py
"""
77. Combinations
Medium

779

47

Favorite

Share
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
"""

# 解法1 模仿77_Subsets解法，暴力搜索所有
"""
Runtime: 736 ms, faster than 21.31% of Python3 online submissions for Combinations.
Memory Usage: 15 MB, less than 61.41% of Python3 online submissions for Combinations.
"""
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:

        self.res = []

        def dfs(nums, path, k):
            for i in range(len(nums)):
                new_path = path + [nums[i]]
                if len(new_path) == k:
                    self.res.append(new_path)
                dfs(nums[i + 1:], new_path, k)

        dfs(list(range(1, n + 1)), [], k)

        return self.res

# 解法2
"""
Runtime: 676 ms, faster than 34.46% of Python3 online submissions for Combinations.
Memory Usage: 15 MB, less than 65.19% of Python3 online submissions for Combinations.
"""
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        self.res = []
        nums = list(range(1, n + 1))

        def combine_helper(nums, k, idx, path):
            if k == 0:
                self.res.append(path[:])
            else:
                for i in range(idx, len(nums)):
                    path.append(nums[i])
                    combine_helper(nums, k - 1, i + 1, path)
                    path.pop()

        combine_helper(nums, k, 0, [])
        return self.res

#解法3
#在解法2基础上的改进
"""
Runtime: 128 ms, faster than 90.70% of Python3 online submissions for Combinations.
Memory Usage: 15.1 MB, less than 40.69% of Python3 online submissions for Combinations.
"""
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        self.res = []
        nums = list(range(1, n + 1))

        def combine_helper(nums, k, idx, path):
            if k == 0:
                self.res.append(path[:])
            else:
                for i in range(idx, len(nums)):
                    #加入提前终止
                    if k > (len(nums) - i):
                        break
                    path.append(nums[i])
                    combine_helper(nums, k - 1, i + 1, path)
                    path.pop()

        combine_helper(nums, k, 0, [])
        return self.res


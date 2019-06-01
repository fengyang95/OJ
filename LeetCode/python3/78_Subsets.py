"""
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
"""


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.res = [[]]

        def dfs(nums, path):
            for i in range(len(nums)):
                new_path = path + [nums[i]]
                self.res.append(new_path)
                dfs(nums[i + 1:], new_path)

        dfs(sorted(nums), [])
        return self.res

"""
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
"""
 

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        self.res = [[]]

        def dfs(nums, path):
            for i in range(len(nums)):
                if i > 0 and nums[i] == nums[i - 1]:
                    continue
                new_path = path + [nums[i]]
                self.res.append(new_path)
                dfs(nums[i + 1:], new_path)

        nums = sorted(nums)
        dfs(nums, [])
        return self.res

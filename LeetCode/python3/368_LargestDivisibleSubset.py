"""
368. Largest Divisible Subset
Medium

567

28

Favorite

Share
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]
"""

"""
Runtime: 436 ms, faster than 18.06% of Python3 online submissions for Largest Divisible Subset.
Memory Usage: 14 MB, less than 5.38% of Python3 online submissions for Largest Divisible Subset.
"""


class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums = sorted(nums)
        res = []
        dp = [[nums[i]] for i in range(len(nums))]
        for i in range(len(nums)):
            for j in range(i):
                if nums[i] % nums[j] == 0:
                    if len(dp[j]) + 1 > len(dp[i]):
                        dp[i] = dp[j] + [nums[i]]
            if len(dp[i]) > len(res):
                res = dp[i]
        return res



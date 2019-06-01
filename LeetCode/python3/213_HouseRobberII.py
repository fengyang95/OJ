"""
213. House Robber II
Medium

863

30

Favorite

Share
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.
Example 2:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
"""


class Solution:
    def rob(self, nums: List[int]) -> int:
        def rob_helper(nums):
            n = len(nums)
            if n < 1:
                return 0
            if n == 1:
                return nums[0]
            if n == 2:
                return max(nums[1], nums[0])
            rob_curr, not_rob_curr = [nums[0]] * n, [0] * n
            for i in range(1, len(nums)):
                rob_curr[i] = not_rob_curr[i - 1] + nums[i]
                not_rob_curr[i] = max(rob_curr[i - 1], not_rob_curr[i - 1])
            return max(rob_curr[-1], not_rob_curr[-1])

        n = len(nums)
        if n < 1:
            return 0
        if n == 1:
            return nums[0]
        if n == 2:
            return max(nums[1], nums[0])

        return max(rob_helper(nums[1:]), rob_helper(nums[:-1]))

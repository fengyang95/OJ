"""
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
"""


class Solution:
    def rob(self, nums: List[int]) -> int:
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

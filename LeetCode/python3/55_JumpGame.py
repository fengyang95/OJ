# -*- coding: utf-8 -*-
# @Time    : 2019/6/8 20:41
# @Author  : Yuanpeng Li
# @FileName: 55_JumpGame.py
"""
55. Jump Game
Medium

1930

196

Favorite

Share
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
"""

"""
Runtime: 56 ms, faster than 30.40% of Python3 online submissions for Jump Game.
Memory Usage: 14.6 MB, less than 51.61% of Python3 online submissions for Jump Game.
"""
# 动态规划
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if len(nums)<2:
            return True
        dp=[nums[0]]*len(nums)
        for i in range(1,len(nums)):
            if dp[i-1]<i:
                return False
            dp[i]=max(dp[i-1],nums[i]+i)
            if dp[i]>=len(nums)-1:
                return True

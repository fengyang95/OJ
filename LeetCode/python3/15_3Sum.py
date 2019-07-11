"""
15. 3Sum
Medium

4048

463

Favorite

Share
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
"""

"""
Runtime: 856 ms, faster than 72.46% of Python3 online submissions for 3Sum.
Memory Usage: 16.7 MB, less than 78.18% of Python3 online submissions for 3Sum.
"""


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        def twoSum(nums, target):
            left, right = 0, len(nums) - 1
            res = []
            while left < right:
                if nums[left] + nums[right] == target:
                    res.append([nums[left], nums[right]])
                    if left + 1 < right and nums[left + 1] == nums[left]:
                        while left + 1 < right and nums[left + 1] == nums[left]:
                            left += 1
                            res.append([nums[left], nums[right]])
                    right -= 1
                elif nums[left] + nums[right] > target:
                    right -= 1
                else:
                    left+= 1
            return res

        nums = sorted(nums)
        res = []
        for i in range(len(nums)):
            if nums[i] > 0:
                break
            if i > 0 and nums[i] == nums[i-1]:
                continue
            two_sum = twoSum(nums[i + 1 :], -nums[i])
            #print(two_sum)
            if len(two_sum) > 0:
                for t in two_sum:
                    res.append((nums[i],t[0],t[1]))
        #print(res)
        return [ele for ele in (set(res))]

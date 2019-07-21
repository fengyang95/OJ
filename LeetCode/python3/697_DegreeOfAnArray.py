# -*- coding: utf-8 -*-
# @Time    : 2019/7/21 17:10
# @Author  : Yuanpeng Li
# @FileName: 697_DegreeOfAnArray.py
"""
697. Degree of an Array
Easy

532

470

Favorite

Share
Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation:
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6
"""

"""
超时！！！
"""
from collections import defaultdict

class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        freqs = defaultdict(int)
        for num in nums:
            freqs[num] += 1
        max_freq_nums = []
        max_freq = 0
        for key in freqs:
            if freqs[key] > max_freq:
                max_freq_nums = [key]
                max_freq = freqs[key]
            elif freqs[key] == max_freq:
                max_freq_nums.append(key)

        min_dist = len(nums)
        for num in max_freq_nums:
            left = 0
            right = len(nums) - 1
            while nums[left] != num:
                left += 1
            while nums[right] != num:
                right -= 1
            dist = right - left + 1
            if dist < min_dist:
                min_dist = dist
        return min_dist

# 同时统计左右边界
"""
Runtime: 264 ms, faster than 13.92% of Python3 online submissions for Degree of an Array.
Memory Usage: 15 MB, less than 15.04% of Python3 online submissions for Degree of an Array.
"""
from collections import defaultdict
class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        freqs,left,right={},{},{}
        for i,num in enumerate(nums):
            if num not in left:
                left[num]=i
            right[num]=i
            freqs[num]=freqs.get(num,0)+1
        res=len(nums)
        max_freq=max(freqs.values())
        for num in freqs:
            if freqs[num]==max_freq:
                res=min(res,right[num]-left[num]+1)
        return res

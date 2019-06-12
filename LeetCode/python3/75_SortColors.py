# -*- coding: utf-8 -*-
# @Time    : 2019/6/12 17:50
# @Author  : Yuanpeng Li
# @FileName: 75_SortColors.py
"""
75. Sort Colors
Medium

1650

158

Favorite

Share
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
"""
"""
Runtime: 32 ms, faster than 97.03% of Python3 online submissions for Sort Colors.
Memory Usage: 13 MB, less than 94.64% of Python3 online submissions for Sort Colors.
"""
# 双指针
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        left,right=0,len(nums)-1
        if len(nums)<2:
            return
        index=0
        while index<=right:
            if nums[index]==0:
                nums[left],nums[index]=nums[index],nums[left]
                left+=1
                index+=1
            elif nums[index]==2:
                nums[right],nums[index]=nums[index],nums[right]
                right-=1
            else:
                index+=1

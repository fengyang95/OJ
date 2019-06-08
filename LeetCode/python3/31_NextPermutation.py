# -*- coding: utf-8 -*-
# @Time    : 2019/6/8 14:36
# @Author  : Yuanpeng Li
# @FileName: 31_NextPermutation.py

"""
31. Next Permutation
Medium

1778

556

Favorite

Share
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
"""
"""
Runtime: 40 ms, faster than 93.00% of Python3 online submissions for Next Permutation.
Memory Usage: 13.3 MB, less than 25.97% of Python3 online submissions for Next Permutation.
"""

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if len(nums)>1:
            found_next_perm=False
            for i in range(len(nums)-1,0,-1):
                if found_next_perm:
                    break
                if nums[i]>nums[i-1]:
                    for j in range(len(nums)-1,-1,-1):
                        if found_next_perm:
                            break
                        if nums[i-1]<nums[j]:
                            nums[j],nums[i-1]=nums[i-1],nums[j]
                            found_next_perm=True
                            nums[i:]=sorted(nums[i:])
            if found_next_perm is False:
                nums[:]=sorted(nums)



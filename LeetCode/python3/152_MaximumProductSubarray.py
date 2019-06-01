"""
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
"""

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        last_max=nums[0]
        last_min=nums[0]
        ret=nums[0]
        for i in range(1,len(nums)):
            if nums[i]<0:
                tmp_max=last_min*nums[i]
                tmp_min=last_max*nums[i]
                last_max=max(tmp_max,nums[i])
                last_min=min(tmp_min,nums[i])
                ret=max(ret,last_max)
            else:
                tmp_max=last_max*nums[i]
                tmp_min=last_min*nums[i]
                last_max=max(tmp_max,nums[i])
                last_min=min(tmp_min,nums[i])
                ret=max(ret,last_max)
        return ret

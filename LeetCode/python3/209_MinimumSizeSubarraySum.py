"""
209. Minimum Size Subarray Sum
Medium

1125

72

Favorite

Share
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example:

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
"""
"""
Runtime: 40 ms, faster than 97.94% of Python3 online submissions for Minimum Size Subarray Sum.
Memory Usage: 14.5 MB, less than 77.88% of Python3 online submissions for Minimum Size Subarray Sum.
"""
# O(N) solution
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        left=0
        curr_sum=0
        res=len(nums)+1
        for i,num in enumerate(nums):
            curr_sum+=num
            if curr_sum>=s:
                while curr_sum>=s:
                    curr_sum-=nums[left]
                    left+=1
                res=min(res,i-left+2)
        if res==len(nums)+1:
            return 0
        else:
            return res
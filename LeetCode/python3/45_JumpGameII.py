"""
45. Jump Game II
Hard

1173

60

Favorite

Share
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
Note:

You can assume that you can always reach the last index.
"""
# 解法一 DP 超时了！！
class Solution:
    def jump(self, nums: List[int]) -> int:
        if len(nums)<2:
            return 0
        dp=[len(nums)]*len(nums)
        dp[0]=0
        for i,num in enumerate(nums):
            for j in range(i+1,i+num+1):
                if j<len(nums):
                    dp[j]=min(dp[j],dp[i]+1)
        return dp[-1]

# 解法二
"""
Runtime: 64 ms, faster than 32.20% of Python3 online submissions for Jump Game II.
Memory Usage: 14.6 MB, less than 43.87% of Python3 online submissions for Jump Game II.
"""
class Solution:
    def jump(self, nums: List[int]) -> int:
        if len(nums)<2:
            return 0
        res,right,furest=0,0,0
        for i in range(len(nums)):
            furest=max(furest,nums[i]+i)
            if furest>=len(nums)-1:
                return res+1
            if i==right:
                right=furest
                res+=1
        return 0
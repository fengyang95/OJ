"""
494. Target Sum
Medium

1375

66

Favorite

Share
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3.
Output: 5
Explanation:

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
"""


class Solution:
    def findTargetSumWays(self, nums,S) -> int:
        cache={}
        def dfs(i,s):
            if (s,i) in cache:
                return cache[(s,i)]
            if i==len(nums):
                if s==S:
                    return 1
                return 0
            res=dfs(i+1,s-nums[i])
            res+=dfs(i+1,s+nums[i])
            cache[(s,i)]=res
            return res
        res=dfs(0,0)
        return res

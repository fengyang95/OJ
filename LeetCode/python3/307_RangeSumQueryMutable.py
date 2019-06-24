"""
307. Range Sum Query - Mutable
Medium

706

60

Favorite

Share
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.

Example:

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:

The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
Accepted
73,231
Submissions
252,894
"""
# 线段树解法
# 参考 https://blog.csdn.net/Yaokai_AssultMaster/article/details/79599809
"""
Runtime: 104 ms, faster than 85.75% of Python3 online submissions for Range Sum Query - Mutable.
Memory Usage: 16.6 MB, less than 85.21% of Python3 online submissions for Range Sum Query - Mutable.
"""


class NumArray:

    def __init__(self, nums: List[int]):
        self.nums = nums
        n = len(nums)
        sum_segment_tree = [0] * (2 * n)
        for i in range(n):
            sum_segment_tree[n + i] = nums[i]
        for i in range(n - 1, -1, -1):
            sum_segment_tree[i] = sum_segment_tree[2 * i] + sum_segment_tree[2 * i + 1]
        self.sum_segment_tree = sum_segment_tree
        self.n = n

    def update(self, i: int, val: int) -> None:
        i += self.n
        self.sum_segment_tree[i] = val
        while i > 1:
            i //= 2
            self.sum_segment_tree[i] = self.sum_segment_tree[2 * i] + self.sum_segment_tree[2 * i + 1]

    def sumRange(self, i: int, j: int) -> int:
        i += self.n
        j += self.n + 1
        sum_val = 0
        while i < j:
            if i & 1 == 1:
                sum_val += self.sum_segment_tree[i]
                i += 1
            if j & 1 == 1:
                j -= 1
                sum_val += self.sum_segment_tree[j]
            i >>= 1
            j >>= 1
        return sum_val

# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(i,val)
# param_2 = obj.sumRange(i,j)
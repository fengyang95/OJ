# -*- coding: utf-8 -*-
# @Time    : 2019/6/2 11:03
# @Author  : Yuanpeng Li
# @FileName: 129_SumRootToLeafNumbers.py

"""
129. Sum Root to Leaf Numbers
Medium

661

24

Favorite

Share
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

Note: A leaf is a node with no children.

Example:

Input: [1,2,3]
    1
   / \
  2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
Example 2:

Input: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
"""

# 递归解法 runtime beats 83.03% memory usage beats 17.83%
# @Time    : 2019/6/2 11:03
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution1:
    def sumNumbers(self, root: TreeNode) -> int:

        self.res = 0

        def dfs(root, path):
            if root is not None:
                path += str(root.val)
                if root.left is None and root.right is None:
                    self.res += int(path)
                    return
                if root.left is not None:
                    dfs(root.left, path)
                if root.right is not None:
                    dfs(root.right, path)

        if root is None:
            return 0
        else:
            dfs(root, '')
            return self.res

# 用堆栈
"""
Runtime: 36 ms, faster than 94.89% of Python3 online submissions for Sum Root to Leaf Numbers.
Memory Usage: 13.3 MB, less than 29.69% of Python3 online submissions for Sum Root to Leaf Numbers.
"""

from collections import deque
class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        self.res = 0
        stk = []
        def dfs(root):
            if root is not None:
                stk.append(str(root.val))
                dfs(root.left)
                dfs(root.right)
                if root.left is None and root.right is None:
                    self.res += (int(''.join(stk)))
                stk.pop()

        if root is None:
            return 0
        else:
            dfs(root)
            return self.res



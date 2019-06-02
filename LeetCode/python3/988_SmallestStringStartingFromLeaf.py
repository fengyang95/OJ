# -*- coding: utf-8 -*-
# @Time    : 2019/6/2 13:51
# @Author  : Yuanpeng Li
# @FileName: 988_SmallestStringStartingFromLeaf.py

"""
@link{https://leetcode.com/problems/smallest-string-starting-from-leaf/}

Given the root of a binary tree, each node has a value from 0 to 25 representing the letters 'a' to 'z': a value of 0 represents 'a', a value of 1 represents 'b', and so on.

Find the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

(As a reminder, any shorter prefix of a string is lexicographically smaller: for example, "ab" is lexicographically smaller than "aba".  A leaf of a node is a node that has no children.)



Example 1:



Input: [0,1,2,3,4,3,4]
Output: "dba"
Example 2:



Input: [25,1,3,1,3,0,2]
Output: "adz"
Example 3:



Input: [2,2,1,null,1,0,null,0]
Output: "abc"


Note:

The number of nodes in the given tree will be between 1 and 8500.
Each node in the tree will have a value between 0 and 25.
"""

# 和129题类似
"""
Runtime: 52 ms, faster than 86.22% of Python3 online submissions for Smallest String Starting From Leaf.
Memory Usage: 14.8 MB, less than 25.60% of Python3 online submissions for Smallest String Starting From Leaf.
"""
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import heapq


class Solution:
    def smallestFromLeaf(self, root: TreeNode) -> str:

        self.paths = []
        self.stk = []

        def dfs(root):
            if root is not None:
                self.stk.append(chr(ord('a') + root.val))
                dfs(root.left)
                dfs(root.right)
                if root.left is None and root.right is None:
                    self.paths.append((''.join(self.stk))[::-1])
                self.stk.pop()

        dfs(root)
        heapq.heapify(self.paths)
        print(self.paths)
        return heapq.nsmallest(1, self.paths)[0]

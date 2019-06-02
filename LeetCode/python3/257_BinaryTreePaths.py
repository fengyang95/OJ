# -*- coding: utf-8 -*-
# @Time    : 2019/6/2 14:14
# @Author  : Yuanpeng Li
# @FileName: 257_BinaryTreePaths.py
"""
257. Binary Tree Paths @link{https://leetcode.com/problems/binary-tree-paths/}
Easy

871

67

Favorite

Share
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
"""


"""
Runtime: 40 ms, faster than 87.35% of Python3 online submissions for Binary Tree Paths.
Memory Usage: 13.2 MB, less than 32.08% of Python3 online submissions for Binary Tree Paths.
"""
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:

        self.res = []
        self.stk = []

        def dfs(root):
            if root is not None:
                self.stk.append(str(root.val))
                dfs(root.left)
                dfs(root.right)
                if root.left is None and root.right is None:
                    self.res.append('->'.join(self.stk))
                self.stk.pop()

        dfs(root)
        return self.res



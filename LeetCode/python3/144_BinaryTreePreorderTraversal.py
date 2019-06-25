# -*- coding: utf-8 -*-
# @Time    : 2019/6/22 20:35
# @Author  : Yuanpeng Li
# @FileName: 144_BinaryTreePreorderTraversal.py
"""
144. Binary Tree Preorder Traversal
Medium

789

39

Favorite

Share
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?z
"""
"""
Runtime: 36 ms, faster than 79.97% of Python3 online submissions for Binary Tree Preorder Traversal.
Memory Usage: 13.1 MB, less than 64.38% of Python3 online submissions for Binary Tree Preorder Traversal.
"""


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        stk = []
        if root is None:
            return []
        res = []
        stk.append(root)
        while len(stk) > 0:
            top = stk.pop()
            res.append(top.val)
            if top.right is not None:
                stk.append(top.right)
            if top.left is not None:
                stk.append(top.left)
        return res

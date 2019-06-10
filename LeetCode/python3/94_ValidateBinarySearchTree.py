# -*- coding: utf-8 -*-
# @Time    : 2019/6/10 21:49
# @Author  : Yuanpeng Li
# @FileName: 94_ValidateBinarySearchTree.py
"""
98. Validate Binary Search Tree
Medium

1951

294

Favorite

Share
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
"""

"""
Runtime: 44 ms, faster than 98.63% of Python3 online submissions for Validate Binary Search Tree.
Memory Usage: 15.5 MB, less than 93.57% of Python3 online submissions for Validate Binary Search Tree.
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:

        def isvalid(root, min_val, max_val):
            if root is None:
                return True
            if root.val >= max_val or root.val <= min_val:
                return False
            return isvalid(root.left, min_val, root.val) and isvalid(root.right, root.val, max_val)

        return isvalid(root, -sys.maxsize, sys.maxsize)


# 中序遍历求解
"""
Runtime: 40 ms, faster than 99.72% of Python3 online submissions for Validate Binary Search Tree.
Memory Usage: 16.9 MB, less than 5.08% of Python3 online submissions for Validate Binary Search Tree.
"""
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def in_order(root, res):
            if root is None:
                return
            in_order(root.left, res)
            res += [root.val]
            in_order(root.right, res)

        res = []
        in_order(root, res)
        return len(res) == len(set(res)) and res == sorted(res)

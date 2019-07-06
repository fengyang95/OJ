# -*- coding: utf-8 -*-
# @Time    : 2019/7/6 15:36
# @Author  : Yuanpeng Li
# @FileName: 450_DeleteNodeInABST.py
"""
450. Delete Node in a BST
Medium

955

59

Favorite

Share
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7
"""
"""
Runtime: 56 ms, faster than 99.91% of Python3 online submissions for Delete Node in a BST.
Memory Usage: 17.5 MB, less than 68.86% of Python3 online submissions for Delete Node in a BST.
"""
# 二叉搜索树节点的删除

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:

    def delete(self, root):
        if root.left is None:
            return root.right
        if root.right is None:
            return root.left
        curr_node = root.left
        if not curr_node.right:
            curr_node.right = root.right
            return curr_node
        prev_node = None
        while curr_node.right:
            prev_node = curr_node
            curr_node = curr_node.right
        prev_node.right = curr_node.left
        curr_node.left = root.left
        curr_node.right = root.right
        return curr_node

    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        curr_node = root
        while curr_node:
            if curr_node.val == key:
                return self.delete(curr_node)
            elif curr_node.val < key:
                if curr_node.right and curr_node.right.val == key:
                    curr_node.right = self.delete(curr_node.right)
                else:
                    curr_node = curr_node.right
            else:
                if curr_node.left and curr_node.left.val == key:
                    curr_node.left = self.delete(curr_node.left)
                else:
                    curr_node = curr_node.left
        return root

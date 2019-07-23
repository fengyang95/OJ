# -*- coding: utf-8 -*-
# @Time    : 2019/7/23 9:14
# @Author  : Yuanpeng Li
# @FileName: 106_ConstructBinaryTreeFromInorderAndPostorderTraversal.py
"""
106. Construct Binary Tree from Inorder and Postorder Traversal
Medium

930

20

Favorite

Share
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
Accepted
160,854
Submissions
400,893
"""
"""
Runtime: 168 ms, faster than 41.01% of Python online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
Memory Usage: 86.1 MB, less than 32.14% of Python online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
"""


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        if len(inorder) == 0:
            return None
        if len(inorder) == 1:
            return TreeNode(inorder[0])
        root_val = postorder[-1]
        index = inorder.index(root_val)
        root = TreeNode(root_val)
        root.left = self.buildTree(inorder[:index], postorder[:index])
        root.right = self.buildTree(inorder[index + 1:], postorder[index:-1])
        return root

# 迭代解法
"""
Runtime: 32 ms, faster than 99.17% of Python online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
Memory Usage: 13.2 MB, less than 99.68% of Python online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
@link{https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/discuss/212565/Python-solution}
"""

class Solution(object):
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        idx = {}
        for i, val in enumerate(inorder):
            idx[val] = i

        head = None
        stack = []
        for val in reversed(postorder):
            if not head:
                head = TreeNode(val)
                stack.append(head)
            else:
                node = TreeNode(val)
                if idx[val] > idx[stack[-1].val]:
                    stack[-1].right = node
                else:
                    while stack and idx[stack[-1].val] > idx[val]:
                        u = stack.pop()
                    u.left = node
                stack.append(node)
        return head

# -*- coding: utf-8 -*-
# @Time    : 2019/7/23 22:59
# @Author  : Yuanpeng Li
# @FileName: 105_ConstructBinaryTreeFromPreorderAndInorderTraversal.py
"""
105. Construct Binary Tree from Preorder and Inorder Traversal
Medium

1851

52

Favorite

Share
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
"""
"""
Runtime: 40 ms, faster than 95.75% of Python online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
Memory Usage: 13.5 MB, less than 95.83% of Python online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
"""

# Definition for a binary tree node.
class TreeNode(object):
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        idx = {}
        for i, val in enumerate(inorder):
            idx[val] = i

        root = None
        stk = []
        for val in preorder:
            if root is None:
                root = TreeNode(val)
                stk.append(root)
            else:
                node = TreeNode(val)
                if idx[stk[-1].val] > idx[val]:
                    stk[-1].left = node
                else:

                    while stk and idx[stk[-1].val] < idx[val]:
                        u = stk.pop()
                    u.right=node
                stk.append(node)
        return root


if __name__=='__main__':
    pre=[3,9,5,10,15,2,4,7]
    inorder=[5,9,3,2,15,4,10,7]
    root=Solution().buildTree(pre,inorder)




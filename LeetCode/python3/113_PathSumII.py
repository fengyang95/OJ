"""
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
"""


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        self.res = []

        def dfs(root, target, path):
            if root is None:
                return
            path.append(root.val)
            if root.left is None and root.right is None and root.val == target:
                self.res.append(path)
                return
            dfs(root.left, target - root.val, path[:])
            dfs(root.right, target - root.val, path[:])
            return

        dfs(root, sum, [])
        return self.res

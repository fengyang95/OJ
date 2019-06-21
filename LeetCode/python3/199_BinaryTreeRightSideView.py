"""
199. Binary Tree Right Side View
Medium

1076

46

Favorite

Share
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

"""
"""
Runtime: 40 ms, faster than 74.99% of Python3 online submissions for Binary Tree Right Side View.
Memory Usage: 13 MB, less than 96.13% of Python3 online submissions for Binary Tree Right Side View.
"""
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque


class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        level = 0
        res = []
        queue = deque()
        if root is None:
            return res
        else:
            queue.append(root)
        while len(queue) > 0:
            newqueue = deque()
            curr_node = queue.popleft()
            res.append(curr_node.val)
            if curr_node.right is not None:
                newqueue.append(curr_node.right)
            if curr_node.left is not None:
                newqueue.append(curr_node.left)
            while len(queue) > 0:
                curr_node = queue.popleft()
                if curr_node.right is not None:
                    newqueue.append(curr_node.right)
                if curr_node.left is not None:
                    newqueue.append(curr_node.left)
            queue = newqueue
        return res




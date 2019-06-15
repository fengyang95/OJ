# -*- coding: utf-8 -*-
# @Time    : 2019/6/15 20:05
# @Author  : Yuanpeng Li
# @FileName: 116_RopulatingNextRightPointerInEachNode.py
"""
116. Populating Next Right Pointers in Each Node
Medium

1018

88

Favorite

Share
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.



Example:



Input: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":{"$id":"6","left":null,"next":null,"right":null,"val":6},"next":null,"right":{"$id":"7","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}

Output: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":{"$id":"6","left":null,"next":null,"right":null,"val":7},"right":null,"val":6},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"7","left":{"$ref":"5"},"next":null,"right":{"$ref":"6"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"7"},"val":1}

Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B.


Note:

You may only use constant extra space.
Recursive approach is fine, implicit stack space does not count as extra space for this problem.
"""
"""
# Definition for a Node.
class Node:
    def __init__(self, val, left, right, next):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""


# 解法1 队列实现层次遍历
"""
Runtime: 52 ms, faster than 88.19% of Python3 online submissions for Populating Next Right Pointers in Each Node.
Memory Usage: 15.2 MB, less than 91.54% of Python3 online submissions for Populating Next Right Pointers in Each Node.
"""
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root is None:
            return root

        level = 0
        queue = deque()
        if root is not None:
            queue.append(root)
        while len(queue)>0:
            n=int(2**level)
            level+=1
            left=queue.popleft()
            if left.left is not None:
                queue.append(left.left)
                queue.append(left.right)
            while n>1:
                right=queue.popleft()
                if right.left is not None:
                    queue.append(right.left)
                    queue.append(right.right)
                left.next=right
                left=right
                n-=1
            left.next=None

        return root

# 解法2
# 不用显式判断每层的结点数
# 可以直接推广到117题
"""
Runtime: 52 ms, faster than 88.19% of Python3 online submissions for Populating Next Right Pointers in Each Node.
Memory Usage: 15.5 MB, less than 20.27% of Python3 online submissions for Populating Next Right Pointers in Each Node.
"""

from collections import deque
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root is None:
            return root
        queue = deque()
        queue.append(root)
        while len(queue)>0:
            new_q=deque()
            left=queue.popleft()
            if left.left is not None:
                new_q.append(left.left)
            if left.right is not None:
                new_q.append(left.right)
            while len(queue)>0:
                right=queue.popleft()
                if right.left is not None:
                    new_q.append(right.left)
                if right.right is not None:
                    new_q.append(right.right)
                left.next=right
                left=right
            queue=new_q

        return root



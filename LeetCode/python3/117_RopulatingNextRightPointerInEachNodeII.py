# -*- coding: utf-8 -*-
# @Time    : 2019/6/15 20:44
# @Author  : Yuanpeng Li
# @FileName: 117_RopulatingNextRightPointerInEachNodeII.py
"""
117. Populating Next Right Pointers in Each Node II
Medium

885

118

Favorite

Share
Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.



Example:



Input: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":null,"next":null,"right":{"$id":"6","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}

Output: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":null,"right":null,"val":7},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"6","left":null,"next":null,"right":{"$ref":"5"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"6"},"val":1}

Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B.


Note:

You may only use constant extra space.
Recursive approach is fine, implicit stack space does not count as extra space for this problem.

"""


"""
Runtime: 164 ms, faster than 94.92% of Python3 online submissions for Populating Next Right Pointers in Each Node II.
Memory Usage: 22 MB, less than 99.53% of Python3 online submissions for Populating Next Right Pointers in Each Node II.
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



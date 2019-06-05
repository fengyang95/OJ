# -*- coding: utf-8 -*-
# @Time    : 2019/6/5 12:28
# @Author  : Yuanpeng Li
# @FileName: 142_LinkedListCycleII.py
"""
142. Linked List Cycle II
Medium

1419

102

Favorite

Share
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

Note: Do not modify the linked list.



Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.


Example 2:

Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.


Example 3:

Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.




Follow up:
Can you solve it without using extra space?
"""

# 双指针 在141题基础上加一步：有环时，快指针从head开始追慢指针
"""
Runtime: 36 ms, faster than 96.81% of Python online submissions for Linked List Cycle II.
Memory Usage: 18.2 MB, less than 67.88% of Python online submissions for Linked List Cycle II
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None or head.next is None:
            return None
        fast, slow = head, head

        while slow is not None and fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next
            if fast == slow:
                break
        if fast is None or fast.next is None:
            return None
        else:
            fast = head
            while fast != slow:
                fast = fast.next
                slow = slow.next
            return slow

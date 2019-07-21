# -*- coding: utf-8 -*-
# @Time    : 2019/7/21 16:58
# @Author  : Yuanpeng Li
# @FileName: 24_SwapNodesInPairs.py
"""
24. Swap Nodes in Pairs
Medium

1244

109

Favorite

Share
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.



Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
"""
# 主要是熟悉指针
"""
Runtime: 40 ms, faster than 18.93% of Python3 online submissions for Swap Nodes in Pairs.
Memory Usage: 13.7 MB, less than 5.26% of Python3 online submissions for Swap Nodes in Pairs.
"""


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        first = head
        second = head.next
        first.next = second.next
        second.next = first
        head = second
        prev = first
        while prev is not None:
            if prev.next is None:
                return head
            if prev.next.next is None:
                return head
            first = prev.next
            second = prev.next.next
            prev.next = second
            tmp = second.next
            second.next = first
            first.next = tmp
            prev = first
        return head





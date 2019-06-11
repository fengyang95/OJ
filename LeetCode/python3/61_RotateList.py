# -*- coding: utf-8 -*-
# @Time    : 2019/6/11 19:27
# @Author  : Yuanpeng Li
# @FileName: 61_RotateList.py
"""
61. Rotate List
Medium

610

816

Favorite

Share
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
"""
# 遍历两次
# 第一次计数 第二次找到断开点
"""
Runtime: 40 ms, faster than 89.81% of Python3 online submissions for Rotate List.
Memory Usage: 13.1 MB, less than 80.09% of Python3 online submissions for Rotate List.
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        curr_node=head
        if curr_node is None:
            return curr_node
        num=1
        while curr_node.next is not None:
            curr_node=curr_node.next
            num+=1
        curr_node.next=head
        k=k%num
        k=num-k
        while k>0:
            curr_node=curr_node.next
            k-=1
        res=curr_node.next
        curr_node.next=None
        return res

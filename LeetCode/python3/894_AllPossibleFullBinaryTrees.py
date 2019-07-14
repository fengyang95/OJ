# -*- coding: utf-8 -*-
# @Time    : 2019/7/14 10:30
# @Author  : Yuanpeng Li
# @FileName: 894_AllPossibleFullBinaryTrees.py
"""
894. All Possible Full Binary Trees
Medium

438

40

Favorite

Share
A full binary tree is a binary tree where each node has exactly 0 or 2 children.

Return a list of all possible full binary trees with N nodes.  Each element of the answer is the root node of one possible tree.

Each node of each tree in the answer must have node.val = 0.

You may return the final list of trees in any order.



Example 1:

Input: 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
Explanation:



Note:

1 <= N <= 20
"""

"""
Runtime: 160 ms, faster than 96.68% of Python3 online submissions for All Possible Full Binary Trees.
Memory Usage: 16.4 MB, less than 70.20% of Python3 online submissions for All Possible Full Binary 
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.cache={}
    def allPossibleFBT(self, N: int) -> List[TreeNode]:
        if N in  self.cache:
            return self.cache[N]
        if N==0:
            return []
        if N==1:
            return [TreeNode(0)]
        res=[]
        for mid_index in range(1,N-1):
            lefts,rights=self.allPossibleFBT(mid_index),self.allPossibleFBT(N-1-mid_index)
            for l in lefts:
                for r in rights:
                    root=TreeNode(0)
                    root.left=l
                    root.right=r
                    res.append(root)
        self.cache[N]=res

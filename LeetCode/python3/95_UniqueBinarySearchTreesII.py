"""
95. Unique Binary Search Trees II
Medium

1237

113

Favorite

Share
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
"""

# 解法1 递归
"""
Runtime: 60 ms, faster than 86.83% of Python3 online submissions for Unique Binary Search Trees II.
Memory Usage: 14.9 MB, less than 76.01% of Python3 online submissions for Unique Binary Search Trees II.
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:

        def dfs(low, high):
            if low > high:
                return [None]
            out = []
            for mid in range(low, high + 1):
                left = dfs(low, mid - 1)
                right = dfs(mid + 1, high)
                for l in left:
                    for r in right:
                        root = TreeNode(mid)
                        root.left = l
                        root.right = r
                        out.append(root)
            return out

        if n < 1:
            return []
        out = dfs(1, n)
        return out



# with cache
"""
Runtime: 56 ms, faster than 96.37% of Python3 online submissions for Unique Binary Search Trees II.
Memory Usage: 14 MB, less than 93.02% of Python3 online submissions for Unique Binary Search Trees II.
"""
class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        self.cache={}
        def dfs(low, high):
            if low > high:
                return [None]
            if (low,high) in self.cache:
                return self.cache[(low,high)]
            out = []
            for mid in range(low, high + 1):
                left = dfs(low, mid - 1)
                right = dfs(mid + 1, high)
                for l in left:
                    for r in right:
                        root = TreeNode(mid)
                        root.left = l
                        root.right = r
                        out.append(root)
            self.cache[(low,high)]=out
            return out

        if n < 1:
            return []
        out = dfs(1, n)
        return out


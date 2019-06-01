"""
337. House Robber III
Medium

1495

31

Favorite

Share
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \
     3   1

Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
"""


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rob(self, root: TreeNode) -> int:

        def rob_helper(root):
            rob_sum, not_rob_sum = 0, 0

            if root is not None:
                rob_sum += root.val
                if root.left is not None:
                    left_rob_sum, left_not_rob_sum = rob_helper(root.left)
                    not_rob_sum = not_rob_sum + left_rob_sum
                    rob_sum = max(rob_sum + left_not_rob_sum, not_rob_sum)
                if root.right is not None:
                    right_rob_sum, right_not_rob_sum = rob_helper(root.right)
                    not_rob_sum = not_rob_sum + right_rob_sum
                    rob_sum = max(rob_sum + right_not_rob_sum, not_rob_sum)

            return rob_sum, not_rob_sum

        return max(rob_helper(root))

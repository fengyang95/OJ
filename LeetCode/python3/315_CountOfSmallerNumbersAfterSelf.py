"""
315. Count of Smaller Numbers After Self
Hard

1155

49

Favorite

Share
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Input: [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
"""
"""
"""

class Node:
    def __init__(self,val):
        self.val=val
        self.left_count=0
        self.count=1
        self.left=None
        self.right=None


    def insert(self,val):
        if val==self.val:
            self.count+=1
            return self.left_count
        elif val<self.val:
            self.left_count+=1
            if self.left is None:
                self.left=Node(val)
                return 0
            else:
                return self.left.insert(val)
        else:
            if self.right is None:
                self.right=Node(val)
                return self.count+self.left_count
            else:
                return self.count+self.left_count+self.right.insert(val)


class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        root=Node(nums[-1])
        ans=[0]
        for num in reversed(nums[:-1]):
            ans.append(root.insert(num))
        return ans[::-1]



# -*- coding: utf-8 -*-
# @Time    : 2019/7/14 11:57
# @Author  : Yuanpeng Li
# @FileName: 895_MaximumFrequencyStack.py
"""
895. Maximum Frequency Stack
Hard

477

10

Favorite

Share
Implement FreqStack, a class which simulates the operation of a stack-like data structure.

FreqStack has two functions:

push(int x), which pushes an integer x onto the stack.
pop(), which removes and returns the most frequent element in the stack.
If there is a tie for most frequent element, the element closest to the top of the stack is removed and returned.


Example 1:

Input:
["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
Output: [null,null,null,null,null,null,null,5,7,5,4]
Explanation:
After making six .push operations, the stack is [5,7,5,7,4,5] from bottom to top.  Then:

pop() -> returns 5, as 5 is the most frequent.
The stack becomes [5,7,5,7,4].

pop() -> returns 7, as 5 and 7 is the most frequent, but 7 is closest to the top.
The stack becomes [5,7,5,4].

pop() -> returns 5.
The stack becomes [5,7,4].

pop() -> returns 4.
The stack becomes [5,7].


Note:

Calls to FreqStack.push(int x) will be such that 0 <= x <= 10^9.
It is guaranteed that FreqStack.pop() won't be called if the stack has zero elements.
The total number of FreqStack.push calls will not exceed 10000 in a single test case.
The total number of FreqStack.pop calls will not exceed 10000 in a single test case.
The total number of FreqStack.push and FreqStack.pop calls will not exceed 150000 across all test cases.
"""

"""
暴力模拟 超时
"""
class FreqStack:

    def __init__(self):
        self.stk = []
        self.freq_dict = {}

    def push(self, x: int) -> None:
        self.stk.append(x)
        if x not in self.freq_dict:
            self.freq_dict[x] = 1
        else:
            self.freq_dict[x] += 1

    def pop(self) -> int:
        sorted_items = sorted(self.freq_dict.items(), key=lambda x: x[1], reverse=True)
        index = 0
        while index < len(sorted_items) - 1 and sorted_items[index][1] == sorted_items[index + 1][1]:
            index += 1
        valid_keys = [it[0] for it in sorted_items[:index + 1]]
        for i in range(len(self.stk) - 1, -1, -1):
            if self.stk[i] in valid_keys:
                self.freq_dict[self.stk[i]] -= 1
                res = self.stk.pop(i)
                return res

# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(x)
# param_2 = obj.pop()

# 参考Discussioni区
"""
Runtime: 240 ms, faster than 91.29% of Python3 online submissions for Maximum Frequency Stack.
Memory Usage: 19.8 MB, less than 86.92% of Python3 online submissions for Maximum Frequency Stack.
"""
from collections import defaultdict


class FreqStack:

    def __init__(self):
        self.stk = [[]]
        self.freq_dict = defaultdict(int)

    def push(self, x: int) -> None:
        self.freq_dict[x] += 1
        if self.freq_dict[x] > len(self.stk):
            self.stk.append([x])
        else:
            self.stk[self.freq_dict[x] - 1].append(x)

    def pop(self) -> int:
        res = self.stk[-1].pop(-1)
        if not self.stk[-1]:
            self.stk.pop(-1)
        self.freq_dict[res] -= 1
        return res

# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(x)
# param_2 = obj.pop()

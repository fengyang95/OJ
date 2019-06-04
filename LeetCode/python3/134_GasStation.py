# -*- coding: utf-8 -*-
# @Time    : 2019/6/4 23:19
# @Author  : Yuanpeng Li
# @FileName: 134_GasStation.py
"""
134. Gas Station
Medium

743

293

Favorite

Share
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.

Note:

If there exists a solution, it is guaranteed to be unique.
Both input arrays are non-empty and have the same length.
Each element in the input arrays is a non-negative integer.
Example 1:

Input:
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]

Output: 3

Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
Example 2:

Input:
gas  = [2,3,4]
cost = [3,4,3]

Output: -1

Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.

"""

#暴力解法 O(N^2)
"""
Runtime: 1868 ms, faster than 12.39% of Python3 online submissions for Gas Station.
Memory Usage: 14.3 MB, less than 17.29% of Python3 online submissions for Gas Station.
"""
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        gain=[g-c for g,c in zip(gas,cost)]
        n=len(gain)
        res=-1
        for i in range(n):
            sum=gain[i]
            if sum<0:
                continue
            for j in range(i+1,i+n):
                sum+=gain[j%n]
                if sum<0:
                    break
            if sum>=0:
                return i
        return res

#
"""
Runtime: 40 ms, faster than 82.54% of Python3 online submissions for Gas Station.
Memory Usage: 13.9 MB, less than 67.29% of Python3 online submissions for Gas Station.
"""

class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if sum(gas)-sum(cost)<0:
            return -1
        n=len(cost)
        index,remain=0,0
        for i in range(n):
            if remain<cost[i]-gas[i]:
                index=i+1
                remain=0
            else:
                remain+=gas[i]-cost[i]
        return index

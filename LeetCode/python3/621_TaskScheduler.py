"""
621. Task Scheduler
Medium

1760

307

Favorite

Share
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.



Example:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.


Note:

The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].
"""

# 全程参考题解
"""
@link{https://leetcode.com/problems/task-scheduler/solution/}
"""

"""
Runtime: 696 ms, faster than 22.82% of Python3 online submissions for Task Scheduler.
Memory Usage: 14.1 MB, less than 5.25% of Python3 online submissions for Task Scheduler.

"""
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        mp=[0]*26
        for task in tasks:
            mp[ord(task)-ord('A')]+=1
        mp=sorted(mp)
        time=0
        while mp[25]>0:
            i=0
            while i<=n:
                if mp[25]==0:
                    break
                if i<26 and mp[25-i]>0:
                    mp[25-i]-=1
                time+=1
                i+=1
            mp=sorted(mp)
        return time

"""
Runtime: 624 ms, faster than 35.57% of Python3 online submissions for Task Scheduler.
Memory Usage: 13.9 MB, less than 5.25% of Python3 online submissions for Task Scheduler.
"""
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        mp=[0]*26
        for task in tasks:
            mp[ord(task)-ord('A')]+=1
        mp=sorted(mp)
        max_val=mp[-1]-1
        idle_slots=max_val*n
        for i in range(24,-1,-1):
            if mp[i]<=0:
                break
            idle_slots-=min(mp[i],max_val)
        if idle_slots>0:
            return idle_slots+len(tasks)
        else:
            return len(tasks)
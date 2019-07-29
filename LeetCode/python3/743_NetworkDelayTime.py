"""
743. Network Delay Time
Medium

683

176

Favorite

Share
There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.



Example 1:



Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2


Note:

N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.
"""

"""
dfs
Runtime: 1104 ms, faster than 10.69% of Python3 online submissions for Network Delay Time.
Memory Usage: 17.5 MB, less than 5.74% of Python3 online submissions for Network Delay Time.
"""
from collections import defaultdict


class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        graph = defaultdict(list)
        for source, target, weight in times:
            graph[source].append((target, weight))
        delay_times = [float('inf')] * (N + 1)

        def dfs(source, delay_times, elapsed):
            if delay_times[source] <= elapsed:
                return
            delay_times[source] = elapsed
            for neighbour in sorted(graph[source], key=lambda x: x[1]):
                dfs(neighbour[0], delay_times, elapsed + neighbour[1])

        dfs(K, delay_times, 0)
        res = max(delay_times[1:])
        if res == float('inf'):
            return -1
        else:
            return int(res)

"""
https://leetcode.com/problems/network-delay-time/discuss/283711/Python-Bellman-Ford-SPFA-Dijkstra-Floyd-clean-and-easy-to-understand
"""

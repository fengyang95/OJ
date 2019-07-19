"""
886. Possible Bipartition
Medium

313

14

Favorite

Share
Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group.

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.



Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false


Note:

1 <= N <= 2000
0 <= dislikes.length <= 10000
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
There does not exist i != j for which dislikes[i] == dislikes[j].
"""
"""
和785一样
"""
from collections import defaultdict, deque


class Solution:
    def possibleBipartition(self, N: int, dislikes: List[List[int]]) -> bool:

        def build_graph(dislikes):
            graph = defaultdict(list)
            for dislike_pair in dislikes:
                a, b = dislike_pair
                graph[a].append(b)
                graph[b].append(a)
            return graph

        graph = build_graph(dislikes)

        filled = [-1] * (N + 1)
        dq = deque()
        for i in range(N + 1):
            if filled[i] == -1:
                dq.append(i)

            while len(dq) > 0:
                curr_it = dq.popleft()
                if filled[curr_it] == -1:
                    filled[curr_it] = 0
                opposite_index = 1 - filled[curr_it]
                for it in graph[curr_it]:
                    if filled[it] == -1:
                        filled[it] = opposite_index
                        dq.append(it)
                    elif filled[it] == filled[curr_it]:
                        return False
        return True






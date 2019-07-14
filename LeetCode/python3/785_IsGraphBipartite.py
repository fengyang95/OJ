"""
785. Is Graph Bipartite?
Medium

683

87

Favorite

Share
Given an undirected graph, return true if and only if it is bipartite.

Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B.

The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  Each node is an integer between 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.

Example 1:
Input: [[1,3], [0,2], [1,3], [0,2]]
Output: true
Explanation:
The graph looks like this:
0----1
|    |
|    |
3----2
We can divide the vertices into two groups: {0, 2} and {1, 3}.
Example 2:
Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
Output: false
Explanation:
The graph looks like this:
0----1
| \  |
|  \ |
3----2
We cannot find a way to divide the set of nodes into two independent subsets.


Note:

graph will have length in range [1, 100].
graph[i] will contain integers in range [0, graph.length - 1].
graph[i] will not contain i or duplicate values.
The graph is undirected: if any element j is in graph[i], then i will be in graph[j].
"""
"""
Runtime: 48 ms, faster than 61.90% of Python3 online submissions for Is Graph Bipartite?.
Memory Usage: 13.4 MB, less than 61.70% of Python3 online submissions for Is Graph Bipartite?.
"""
from collections import deque
class Solution:
    def isBipartite(self, graph) -> bool:
        sets = [set(), set()]
        n = len(graph)
        curr_set = 0
        filled = [-1] * n
        dq=deque()
        for i in range(n):
            if filled[i]==-1:
                dq.append(i)
            while len(dq)>0:
                i=dq.popleft()
                if filled[i] != -1:
                    curr_set = filled[i]
                else:
                    sets[curr_set].add(i)
                    filled[i] = curr_set
                for con in graph[i]:
                    if filled[con] == -1:
                        dq.append(con)
                        sets[1 - curr_set].add(con)
                        filled[con] = 1 - curr_set
                    else:
                        if filled[con] == curr_set:
                            return False
        return True

"""
"""
class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:

        num_of_node = len(graph)
        A_set = set()
        B_set = set()
        temp_set = set()
        D = set(str(i) for i in range(num_of_node))

        # print(D)

        def devideSet(index, A_set, B_set):
            temp_set.clear()
            for num in graph[index]:
                temp_set.add(str(num))
            if temp_set:  # why only .update
                if not A_set:
                    A_set.add(str(index))

                    B_set.update(temp_set)
                elif str(index) in A_set:
                    B_set.update(temp_set)
                elif str(index) in B_set:
                    # A_set = A_set | temp_set
                    A_set.update(temp_set)
                else:
                    A_set.add(str(index))
                    B_set.update(temp_set)
            else:
                return -1

        while D:
            array = list(D)
            D.remove(array[0])
            devideSet(int(array[0]), A_set, B_set)
            temp_set.clear()

            while not (A_set | B_set).isdisjoint(D):
                array = list((A_set | B_set) & D)
                D.remove(array[0])
                devideSet(int(array[0]), A_set, B_set)
                if not A_set.isdisjoint(B_set):
                    return False

        if A_set.isdisjoint(B_set):
            return True




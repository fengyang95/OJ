"""
310. Minimum Height Trees
Medium

987

60

Favorite

Share
For an undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1 :

Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3

Output: [1]
Example 2 :

Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5

Output: [3, 4]
Note:

According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
"""
"""
Runtime: 568 ms, faster than 16.82% of Python3 online submissions for Minimum Height Trees.
Memory Usage: 16.3 MB, less than 90.26% of Python3 online submissions for Minimum Height Trees.
"""
#解法1
#拓扑排序的思路
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:

        graph = {}
        for (l, r) in edges:
            if l in graph:
                graph[l].append(r)
            else:
                graph[l] = [r]
            if r in graph:
                graph[r].append(l)
            else:
                graph[r] = [l]

        while len(graph) > 2:
            keys = [key for key in graph if len(graph[key]) == 1]
            for key in keys:
                graph[graph[key][0]].remove(key)
                graph.pop(key)
        return list(graph.keys()) if graph else [0]

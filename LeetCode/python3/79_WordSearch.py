"""
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
"""


class Solution:
    def exist(self, board, word: str) -> bool:
        nr, nc = len(board), len(board[0])

        def dfs(b, i, j, k):
            if k == len(word):
                return True
            if 0 <= i < nr and 0 <= j < nc and word[k] == b[i][j]:

                res = False
                for (ni, nj) in [(i - 1, j), (i, j - 1), (i, j + 1), (i + 1, j)]:
                    tmp, board[i][j] = board[i][j], None
                    res = dfs(b, ni, nj, k + 1)
                    board[i][j] = tmp
                    if res is True:
                        return True
            return False

        for i in range(nr):
            for j in range(nc):
                if word[0] == board[i][j]:
                    if dfs(board, i, j, 0) is True:
                        return True
                else:
                    continue
        return False

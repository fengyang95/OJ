"""
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'.
Two cells are connected if they are adjacent cells connected horizontally or vertically.
"""


class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        nr, nc = len(board), len(board[0]) if len(board) > 0 else 0
        if board is None or nc < 2 or nr < 2:
            return

        def neighbours(r, c):
            if 0 <= r - 1 < nr:
                yield r - 1, c
            if 0 <= r + 1 < nr:
                yield r + 1, c
            if 0 <= c - 1 < nc:
                yield r, c - 1
            if 0 <= c + 1 < nc:
                yield r, c + 1

        def dfs(board, r, c):
            if board[r][c] == 'O':
                board[r][c] = 'V'
                for nr, nc in neighbours(r, c):
                    dfs(board, nr, nc)
            else:
                return

        for i in range(nc):
            dfs(board, 0, i)
            dfs(board, nr - 1, i)
        for i in range(nr):
            dfs(board, i, 0)
            dfs(board, i, nc - 1)

        for i in range(nr):
            for j in range(nc):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                if board[i][j] == 'V':
                    board[i][j] = 'O'

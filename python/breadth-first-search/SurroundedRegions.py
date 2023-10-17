from typing import List
from collections import deque

class Solution:
    def solve(self, board: List[List[str]]) -> None:

        rows, cols = len(board), len(board[0])
        distances = [(-1, 0), (0, -1), (0, 1), (1, 0)]

        def is_valid_cell(row, col):
            return 0 <= row < rows and 0 <= col < cols
        
        queue = deque()

        for i in range(rows):
            for j in range(cols):
                if i == 0 or i == rows - 1 or j == 0 or j == cols - 1:
                    if board[i][j] == 'O':
                        queue.append((i, j))
                        board[i][j] = 'V'
                    
        while queue:
            row, col = queue.popleft()

            for direction in distances:
                new_row, new_col = row + direction[0], col + direction[1]
                if is_valid_cell(new_row, new_col) and board[new_row][new_col] == 1:
                    queue.append((new_row, new_col))
                    board[new_row][new_col] = 'V'

        
        for i in range(rows):
            for j in range(cols):
                if board[i][j] == 'V':
                    board[i][j] = 'O'
                else:
                    board[i][j] = 'X'
    


from ast import List
from collections import deque

class Solution:
        
    def orangesRotting(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        distances = [(-1, 0), (0, -1), (0, 1), (1, 0)]
        fresh_oranges = 0
        
        def is_valid_cell(row, col):
            return 0 <= row < rows and 0 <= col < cols
        
        queue = deque()
        
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 2:
                    queue.append((i, j, 0))
                elif grid[i][j] == 1:
                    fresh_oranges += 1

        
        min_time = 0
        
        while queue:
            row, col, time = queue.popleft()
            
            for direction in distances:
                new_row, new_col = row + direction[0], col + direction[1]
                
                if is_valid_cell(new_row, new_col) and grid[new_row][new_col] == 1:
                    queue.append((new_row, new_col, time + 1))
                    grid[new_row][new_col] = 2
                    min_time = time + 1
                    fresh_oranges -= 1
        
        return min_time if fresh_oranges == 0 else -1

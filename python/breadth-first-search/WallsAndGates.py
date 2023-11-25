from typing import List
from collections import deque

class Node:
    def __init__(self, row, col, distance):
        self.row = row
        self.col = col
        self.distance = distance

class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        MAX = 2147483647
        directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        rows = len(rooms)
        cols = len(rooms[0])

        queue = deque()

        for i in range(rows):
            for j in range(cols):
                if rooms[i][j] == 0:
                    queue.append(Node(i, j, 0))

        while queue:
            curr_node = queue.popleft()

            for direction in directions:
                new_row = curr_node.row + direction[0]
                new_col = curr_node.col + direction[1]
                
                if 0 <= new_row < rows and 0 <= new_col < cols and rooms[new_row][new_col] == MAX:
                    rooms[new_row][new_col] = curr_node.distance + 1
                    queue.append(Node(new_row, new_col, curr_node.distance + 1))

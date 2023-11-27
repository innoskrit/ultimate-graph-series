directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]

def solve(row, col, matrix, rows, cols):
    if row == rows - 1 and col == cols - 1:
        return True

    can_reach = False
    for direction in directions:
        new_row = row + direction[0]
        new_col = col + direction[1]
        if 0 <= new_row < rows and 0 <= new_col < cols and matrix[new_row][new_col] == 0:
            matrix[new_row][new_col] = 1
            can_reach = can_reach or solve(new_row, new_col, matrix, rows, cols)
            if can_reach:
                return can_reach

    return can_reach

def can_reach(matrix):
    return solve(0, 0, matrix, len(matrix), len(matrix[0]))

if __name__ == "__main__":
    matrix = [
        [0, 0, 0, 0],
        [0, 0, 0, 1],
        [0, 0, 0, 0],
        [0, 1, 0, 0]
    ]

    print(can_reach(matrix))

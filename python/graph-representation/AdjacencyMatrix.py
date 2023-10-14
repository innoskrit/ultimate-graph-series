class AdjacencyMatrix:

    def print_graph(self, grid, n):
        for i in range(n):
            print(i, end = " : ")
            for j in range(n):
                if grid[i][j] == 1:
                    print(j, end = " ")
            print()

if __name__ == '__main__':
    grid = [
        [0, 1, 1, 0, 0, 0],
        [1, 0, 1, 1, 1, 0],
        [1, 1, 0, 0, 0, 1],
        [0, 1, 0, 0, 1, 1],
        [0, 1, 0, 1, 0, 0],
        [0, 0, 1, 1, 0, 0]
    ]
    n = 6

    adjacencyMatrix = AdjacencyMatrix() 
    adjacencyMatrix.print_graph(grid, n)
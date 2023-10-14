class AdjacencyMatrix {

    public void printGraph(int[][] grid, int n) {
        for(int i = 0; i < n; i++) {
            System.out.print(i + " : ");
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    System.out.print(j + " ");
                }
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int[][] grid = new int[][]{
            {0, 1, 1, 0, 0, 0},
            {1, 0, 1, 1, 1, 0},
            {1, 1, 0, 0, 0, 1},
            {0, 1, 0, 0, 1, 1},
            {0, 1, 0, 1, 0, 0},
            {0, 0, 1, 1, 0, 0}
        };
        int n = 6;
        
        AdjacencyMatrix adjacencyMatrix = new AdjacencyMatrix();
        adjacencyMatrix.printGraph(grid, n);
        
    }
}
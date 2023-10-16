class Node {
    int row, col, time;
    public Node(int row, int col, int time) {
        this.row = row;
        this.col = col;
        this.time = time;
    }
}

class Solution {

    int[][] distances = new int[][]{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    private boolean isValidCell(int row, int col, int rows, int cols) {
        if(row >= 0 && row < rows && col >= 0 && col < cols) 
            return true;
        else 
            return false;
    }

    public int orangesRotting(int[][] grid) {
        
        int rows = grid.length;
        int cols = grid[0].length;
        int freshOranges = 0;

        Queue<Node> queue = new LinkedList<>();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 2) {
                    queue.add(new Node(i, j, 0));
                } else if(grid[i][j] == 1) {
                    freshOranges += 1;
                }
            }
        }

        int minTime = 0;

        while(!queue.isEmpty()) {
            Node node = queue.poll();
            for(int[] distance : distances) {
                int newRow = node.row + distance[0];
                int newCol = node.col + distance[1];
                if(isValidCell(newRow, newCol, rows, cols) && grid[newRow][newCol] == 1) {
                    queue.add(new Node(newRow, newCol, node.time + 1));
                    grid[newRow][newCol] = 2;
                    minTime = node.time + 1;
                    freshOranges -= 1;
                }
            }
        }

        return freshOranges == 0 ? minTime : -1;
    }
}
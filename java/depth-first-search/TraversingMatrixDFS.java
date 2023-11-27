public class TraversingMatrixDFS {

    static int[][] directions = new int[][]{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    private static boolean solve(int row, int col, int[][] matrix, int rows, int cols) {
    
        if(row == rows - 1 && col == cols - 1) {
            return true;
        }

        boolean canReach = false;
        for(int[] direction : directions) {
            int newRow = row + direction[0];
            int newCol = col + direction[1];
            if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && matrix[newRow][newCol] == 0) {
                matrix[newRow][newCol] = 1;
                canReach = canReach || solve(newRow, newCol, matrix, rows, cols);
                if(canReach) return canReach;
            }
        }

        return canReach;
    }
    private static boolean canReach(int[][] matrix) {
        return solve(0, 0, matrix, matrix.length, matrix[0].length);
    }
    public static void main(String[] args) {
        int[][] matrix = new int[][] {
            {0, 0, 0, 0},
            {0, 0, 0, 1},
            {0, 0, 1, 0},
            {0, 1, 0, 0}
        };

        System.out.println(canReach(matrix));
    }
}

import java.util.*;

class Node {
    int row, col, distance;
    public Node(int row, int col, int distance) {
        this.row = row;
        this.col = col;
        this.distance = distance;
    }
}

class Solution {

    private boolean isValid(int row, int col, int rows, int cols) {
        return (row < rows && row >= 0 && col < cols && col >= 0);
    }
    
    public void wallsAndGates(int[][] rooms) {
        int[][] directions = new int[][]{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int rows = rooms.length;
        int cols = rooms[0].length;

        Queue<Node> queue = new LinkedList<>();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(rooms[i][j] == 0) {
                    queue.add(new Node(i, j, 0));
                }
            }
        }

        while(!queue.isEmpty()) {
            Node currNode = queue.poll();
            for(int[] direction : directions) {
                int newRow = currNode.row + direction[0];
                int newCol = currNode.col + direction[1];
                if(isValid(newRow, newCol, rows, cols) && rooms[newRow][newCol] == Integer.MAX_VALUE) {
                    rooms[newRow][newCol] = currNode.distance + 1;
                    queue.add(new Node(newRow, newCol, currNode.distance + 1));
                }
            }
        }
    }
}
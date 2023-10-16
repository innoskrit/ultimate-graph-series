class Node {
public:
    int row, col, time;
    Node(int row, int col, int time) {
        this->row = row;
        this->col = col;
        this->time = time;
    }  
};

class Solution {
public:

    bool isValidCell(int row, int col, int rows, int cols) {
        if(row >= 0 && row < rows && col >= 0 && col < cols) 
            return true;
        else 
            return false;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        int freshOranges = 0;

        vector<vector<int>> distances = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

        queue<Node> queue;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    queue.push(Node(i, j, 0));
                } else if(grid[i][j] == 1) {
                    freshOranges += 1;
                }
            }
        }

        int minTime = 0;

        while (!queue.empty()) {
            Node node = queue.front();
            queue.pop();

            for (const auto& distance : distances) {
                int newRow = node.row + distance[0];
                int newCol = node.col + distance[1];

                if (isValidCell(newRow, newCol, rows, cols) && grid[newRow][newCol] == 1) {
                    queue.push(Node(newRow, newCol, node.time + 1));
                    grid[newRow][newCol] = 2;
                    minTime = node.time + 1;
                    freshOranges -= 1;
                }
            }
        }

        return freshOranges == 0 ? minTime : -1;
    }
};

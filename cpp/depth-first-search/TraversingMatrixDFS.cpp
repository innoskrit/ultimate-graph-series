#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool solve(int row, int col, vector<vector<int>>& matrix, int rows, int cols) {
    if (row == rows - 1 && col == cols - 1) {
        return true;
    }

    bool canReach = false;
    for (const auto& direction : directions) {
        int newRow = row + direction[0];
        int newCol = col + direction[1];
        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && matrix[newRow][newCol] == 0) {
            matrix[newRow][newCol] = 1;
            canReach = canReach || solve(newRow, newCol, matrix, rows, cols);
            if (canReach) return canReach;
        }
    }

    return canReach;
}

bool canReach(vector<vector<int>>& matrix) {
    return solve(0, 0, matrix, matrix.size(), matrix[0].size());
}

int main() {
    vector<vector<int>> matrix = {
        {0, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0},
        {0, 1, 0, 0}
    };

    cout << canReach(matrix) << endl;

    return 0;
}

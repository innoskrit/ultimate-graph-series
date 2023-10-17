#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int row, col;
    Node(int row, int col) {
        this->row = row;
        this->col = col;
    }
};

class Solution {
public:

    vector<vector<int>> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    bool isValidCell(int row, int col, int rows, int cols) {
        if(row >= 0 && row < rows && col >= 0 && col < cols) 
            return true;
        else 
            return false;
    }

    void solve(vector<vector<char>>& board) {

        int rows = board.size();
        int cols = board[0].size();
        
        queue<Node> queue;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                    if(board[i][j] == 'O') {
                        queue.push(Node(i, j));
                        board[i][j] = 'V';
                    }
                }
            }
        }

        while(!queue.empty()) {
            Node node = queue.front();
            queue.pop();

            for(auto& direction : directions) {
                int newRow = node.row + direction[0];
                int newCol = node.col + direction[1];
                if(isValidCell(newRow, newCol, rows, cols) && board[newRow][newCol] == 'O') {
                    queue.push(Node(newRow, newCol));
                    board[newRow][newCol] = 'V';
                }
            }
        }

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == 'V') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};
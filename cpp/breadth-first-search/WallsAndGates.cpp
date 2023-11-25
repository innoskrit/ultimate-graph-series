#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int row, col, distance;
    Node(int row, int col, int distance) {
        this->row = row;
        this->col = col;
        this->distance = distance;
    }
};

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int directions[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int rows = rooms.size();
        int cols = rooms[0].size();

        queue<Node> q;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (rooms[i][j] == 0) {
                    q.push(Node(i, j, 0));
                }
            }
        }

        while (!q.empty()) {
            Node currNode = q.front();
            q.pop();

            for (auto& direction : directions) {
                int newRow = currNode.row + direction[0];
                int newCol = currNode.col + direction[1];

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
                    rooms[newRow][newCol] == INT_MAX) {
                    rooms[newRow][newCol] = currNode.distance + 1;
                    q.push(Node(newRow, newCol, currNode.distance + 1));
                }
            }
        }
    }
};

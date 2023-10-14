#include <bits/stdc++.h>
using namespace std;

class AdjacencyMatrix {
public:
    void printGraph(vector<vector<int>> &grid, int n) {
        for(int i = 0; i < n; i++) {
            cout << i << " : ";
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }   
};

int main(int argc, char const *argv[]) {
    vector<vector<int>> grid = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 1, 1, 0},
        {1, 1, 0, 0, 0, 1},
        {0, 1, 0, 0, 1, 1},
        {0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 0}
    };
    int n = 6;

    AdjacencyMatrix adjacencyMatrix;
    adjacencyMatrix.printGraph(grid, n);
}

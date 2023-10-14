#include <bits/stdc++.h>
using namespace std;

class AdjacencyList {
public:
    vector<vector<int>> buildGraph(vector<vector<int>> &edges, int n) {
        vector<vector<int>> graph;
        
        for(int i = 0; i < n; i++) {
            vector<int> nbrs;
            graph.push_back(nbrs);
        }

        for(auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return graph;
    }   
};

int main(int argc, char const *argv[]) {
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {1, 4}, {2, 5}, {3, 4}, {3, 5}};
    int n = 6;

    AdjacencyList adjacencyList;
    
    vector<vector<int>> graph = adjacencyList.buildGraph(edges, n);
    for(int i = 0; i < n; i++) {
        cout << i << " : ";
        for(auto &nbr : graph[i]) {
            cout << nbr << " ";
        }
        cout << endl;
    }
}

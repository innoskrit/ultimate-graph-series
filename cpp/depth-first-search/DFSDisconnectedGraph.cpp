#include<bits/stdc++.h>
using namespace std;

class DFSDisconnectedGraph {
public:
    vector<vector<int>> buildGraph(vector<vector<int>>& edges, int n) {
        vector<vector<int>> graph(n);
        
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return graph;
    }

    void solve(int node, vector<int>& dfsAnswer, vector<vector<int>>& graph, vector<bool>& visited) {
        dfsAnswer.push_back(node);
        visited[node] = true;
        for (int nbr : graph[node]) {
            if (!visited[nbr]) {
                solve(nbr, dfsAnswer, graph, visited);
            }
        }
    }

    vector<int> depthFirstSearch(vector<vector<int>>& edges, int n) {
        vector<vector<int>> graph = buildGraph(edges, n);
        vector<int> dfsAnswer;
        vector<bool> visited(n, false);
        for(int src = 0; src < n; src++) {
            if(!visited[src]) {
                solve(src, dfsAnswer, graph, visited);
            }
        }
        return dfsAnswer;
    }
};

int main() {
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {1, 4}, {2, 5}, {3, 4}, {3, 5}, {6, 7}, {7, 8}};
    int n = 9;
    
    DFSDisconnectedGraph dfs;
    
    vector<int> dfsAnswer = dfs.depthFirstSearch(edges, n);
    for (int node : dfsAnswer) {
        cout << node << " ";
    }

    return 0;
}
